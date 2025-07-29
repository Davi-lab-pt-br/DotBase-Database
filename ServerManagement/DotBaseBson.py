import json
import os
from bson import BSON

class DotBSON:
    @staticmethod
    def toBSON(filepath):
        if not filepath.endswith(".json"):
            raise SyntaxError(f"{filepath} is not compatible with BSON conversion")

        with open(filepath, "r") as f:
            data_json = json.load(f)

        new_filepath = filepath[:-5] + ".bson"

        bson_data = BSON.encode(data_json)
        with open(new_filepath, "wb") as f:
            f.write(bson_data)

        os.remove(filepath)  # Apaga o JSON original

    @staticmethod
    def toJSON(filepath):
        if not filepath.endswith(".bson"):
            raise SyntaxError(f"{filepath} is not compatible with JSON conversion")

        with open(filepath, "rb") as f:
            data_bson = f.read()

        data_json = BSON(data_bson).decode()

        new_filepath = filepath[:-5] + ".json"

        with open(new_filepath, "w") as f:
            json.dump(data_json, f, indent=4)

        os.remove(filepath)  # Apaga o BSON original