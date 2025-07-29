import socket
import threading
import os
import json
from bson import BSON
import DotBaseBson

dbb = DotBaseBson.DotBSON()

os.system("cls")
os.system("title DotBase Server")

HOST = "127.0.0.1"
PORT = 3006

def load_tables():
    if os.path.exists("DotBaseTables.bson"):
        with open("DotBaseTables.bson", "rb") as f:
            data_bson = f.read()
        return BSON(data_bson).decode()
    else:
        return {}

def save_tables(data_json):
    json_file = "DotBaseTables.json"
    with open(json_file, "w", encoding="utf-8") as f:
        json.dump(data_json, f, indent=4)
    dbb.toBSON(json_file)

def handle_client(conn, addr):
    print(f"\nConnected by {addr}")
    with conn:
        while True:
            try:
                data = conn.recv(4096)
                if not data:
                    break

                msg = data.decode('utf-8').strip()
                print(f"Received: {msg}")

                if msg.startswith("TABLE_CREATE "):
                    tablename = msg.removeprefix('TABLE_CREATE '). removesuffix('').strip()

                    data_json = load_tables()

                    if tablename not in data_json:
                        data_json[tablename] = []
                        save_tables(data_json)
                        conn.sendall(f"Table '{tablename}' created successfully.".encode('utf-8'))
                    else:
                        conn.sendall(f"Table '{tablename}' already exists.".encode('utf-8'))

                else:
                    conn.sendall("Unknown command.".encode('utf-8'))

            except Exception as e:
                print(f"Error with {addr}: {e}")
                break

    print(f"\nConnection closed: {addr}")

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((HOST, PORT))
        s.listen()
        print(f"\nServer listening on {HOST}:{PORT}")

        while True:
            conn, addr = s.accept()
            thread = threading.Thread(target=handle_client, args=(conn, addr), daemon=True)
            thread.start()

if __name__ == "__main__":
    main()