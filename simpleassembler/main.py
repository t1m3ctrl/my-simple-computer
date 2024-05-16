import sys
import re

codes = [0] * 128 # Список, который будем преобразовывать в бинарник, и загружать в оперативку.

def sc_commandEncode(sign, command, operand): # Кодируем знак, команду, операнд под формат
    cmd = sign << 14
    command = command << 7
    cmd |= command
    cmd |= operand
    return cmd

def encode_line(mem, cmd, op):
    cmds = { # Словарь команд
        "=": -1,
        "NOP": 0x00,
        "CPUINFO": 0x01,
        "READ": 0x0A,
        "WRITE": 0x0B,
        "LOAD": 0x14,
        "STORE": 0x15,
        "ADD": 0x1E,
        "SUB": 0x1F,
        "DIVIDE": 0x20,
        "MUL": 0x21,
        "JUMP": 0x28,
        "JNEG": 0x29,
        "JZ": 0x2A,
        "HALT": 0x2B,
        "NOT": 0x33,
        "AND": 0x34,
        "OR": 0x35,
        "XOR": 0x36,
        "JNS": 0x37,
        "JC": 0x38,
        "JNC": 0x39,
        "JP": 0x3A,
        "JNP": 0x3B,
        "CHL": 0x3C,
        "SHR": 0x3D,
        "RCL": 0x3E,
        "RCR": 0x3F,
        "NEG": 0x40,
        "ADDC": 0x41,
        "SUBC": 0x42,
        "LOGLC": 0x43,
        "LOGRC": 0x44,
        "RCCL": 0x45,
        "RCCR": 0x46,
        "MOVA": 0x47,
        "MOVR": 0x48,
        "MOVCA": 0x49,
        "MOVCR": 0x4A,
        "ADDC": 0x4B,
        "SUBC": 0x4C
    }

    if cmd not in cmds: # Если команды нет в списке выводим ошибку
        print(f"Unknown command: {cmd}")
        sys.exit(-1)

    if cmd == "=": # Если равенство, то просто присваиваем ячейке операнд
        codes[mem] = op
    else: # Иначе кодируем команду и операнд, и присваиваем ячейке
        parsedCmd = cmds[cmd]
        encodedCommand = sc_commandEncode(0, parsedCmd, op)
        codes[mem] = encodedCommand

def parse_line(line): # Парсит строку, разбивает по пробелам и кодирует полученные токены
    tokens = re.split('\s+', line)
    if len(tokens) < 3:
        print(f"Invalid line: {line}")
        sys.exit(-1)

    mem = int(tokens[0])
    command = tokens[1]
    operand = int(tokens[2])

    encode_line(mem, command, operand)

def main(file_path): 
    with open(file_path, 'r') as file:
        for line in file: # Парсим строку, удаляем комментарии пробелы в начале и в конце
            commentPos = line.find(';')
            if commentPos != -1:
                line = line[:commentPos]
            line = line.strip()
            if line:
                parse_line(line)

    with open("memory.bin", 'wb') as outFile: # Записываем полученные коды, в бинарник
        for code in codes:
            outFile.write(code.to_bytes(4, byteorder='little'))

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("First argument should be the path!")
        sys.exit(-1)

    main(sys.argv[1])
