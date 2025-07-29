import socket
    
class DotBase:
    def __init__(self):
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        pass
    
    def connect_Server(self, host, port):
        try:
            self.client_socket.connect((host, port))
            print("✅ Connected to Server.")
        except Exception as e:
            print("❌ Error in the connection:", e)
        
    def send_Message(self, message):
        message = str(message)
        self.client_socket.sendall(message.encode())
        print("📤 Message sent.")
        answer = self.client_socket.recv(1024)
        print("📥 Asnwer from the server:", answer.decode())
        
    def end_Connection(self):
        self.client_socket.close()
        print("🔌 Connection ended.")