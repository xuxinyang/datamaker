# -*-encoding=utf-8-*-
import os

def read_file(filename:str) -> list:
    with open(filename, "r", encoding="utf-8") as f:
        lines = f.readlines()
    return lines

def data_process(data:str) -> bool:
    print(data)

if __name__ == "__main__":
    filename = "data.config"
    data = read_file(filename)
    if data_process(data):
        print("Data Process Successful!")
    else:
        print("Data Process Failed!")