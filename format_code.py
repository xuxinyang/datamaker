# -*-encoding=utf-8-*-
"""
    Format gen_input.cpp and stand_code.cpp
"""

def read_file(file_name) -> str:
    if file_name == "gen_input.cpp":
        pass
    elif file_name == "stand_code.cpp":
        with open(file_name, "r", encoding="utf-8") as f:
            lines = f.readlines()
    return lines

def write_file(file_name, content) -> bool:
    flag = False
    if file_name == "gen_input.cpp":
        pass
    elif file_name == "stand_code.cpp":
        with open(file_name, "w", encoding="utf-8") as f:
            f.writelines(content)
            flag = True
    return flag

def format_code(content) -> str:
    start_curly = 0
    for line in range(len(content)):
        # Find function main
        if "int main()" in content[line]:
            print("--------------------------Processing main function--------------------------")
            content[line] = content[line].replace("int main()", "int main(int argc, char *argv[])")
            start_curly = 1
        if start_curly == 1 and "{" in content[line]:
            content[line] += "\tstring filename = argv[1];\n"
            content[line] += "\tstring outfilename = argv[2];\n"
            content[line] += "\tfreopen(filename.c_str(), \"r\", stdin);\n"
            content[line] += "\tfreopen(outfilename.c_str(), \"w\", stdout);\n"
            break
    return content

        

if __name__ == '__main__':
    # Process gen_input.cpp

    # Process stand_code.cpp
    input_name = 'stand_code.cpp'
    output_name = 'stand_code.cpp'
    input_content = read_file(input_name)
    output_content = format_code(input_content)
    flag = write_file(output_name, output_content)
    if flag:
        print("File Writed Successful!")
    else:
        print("File Writed Failed!")
