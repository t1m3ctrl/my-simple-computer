#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> codes = vector<int>(128);

int sc_commandEncode(int sign, int command, int operand)
{
    int cmd = sign << 14;
    command = command << 7;
    cmd |= command;
    cmd |= operand;
    return cmd;
}

void encode_line(int mem, string cmd, int op)
{
    unordered_map<string, int> cmds = {
        {"=", -1},
        {"NOP", 0x00},
        {"CPUINFO", 0x01},
        {"READ", 0x0A},
        {"WRITE", 0x0B},
        {"LOAD", 0x14},
        {"STORE", 0x15},
        {"ADD", 0x1E},
        {"SUB", 0x1F},
        {"DIVIDE", 0x20},
        {"MUL", 0x21},
        {"JUMP", 0x28},
        {"JNEG", 0x29},
        {"JZ", 0x2A},
        {"HALT", 0x2B},
        {"NOT", 0x33},
        {"AND", 0x34},
        {"OR", 0x35},
        {"XOR", 0x36},
        {"JNS", 0x37},
        {"JC", 0x38},
        {"JNC", 0x39},
        {"JP", 0x3A},
        {"JNP", 0x3B},
        {"CHL", 0x3C},
        {"SHR", 0x3D},
        {"RCL", 0x3E},
        {"RCR", 0x3F},
        {"NEG", 0x40},
        {"ADDC", 0x41},
        {"SUBC", 0x42},
        {"LOGLC", 0x43},
        {"LOGRC", 0x44},
        {"RCCL", 0x45},
        {"RCCR", 0x46},
        {"MOVA", 0x47},
        {"MOVR", 0x48},
        {"MOVCA", 0x49},
        {"MOVCR", 0x4A},
        {"ADDC", 0x4B},
        {"SUBC", 0x4C}};

    if (cmds.find(cmd) == cmds.end())
    {
        cerr << "Unknown command: " << cmd << endl;
        exit(-1);
    }

    if (cmd == "=")
    {
        codes[mem] = op;
    }
    else
    {
        int parsedCmd = cmds[cmd];
        int encodedCommand = sc_commandEncode(0, parsedCmd, op);
        codes[mem] = encodedCommand;
    }
}

void parse_line(string line)
{
    stringstream ss(line);
    string token;
    vector<string> tokens;

    while (getline(ss, token, ' '))
    {
        if (!token.empty())
        {
            tokens.push_back(token);
        }
    }

    if (tokens.size() < 3)
    {
        cerr << "Invalid line: " << line << endl;
        exit(-1);
    }

    int mem = stoi(tokens[0]);
    string command = tokens[1];
    int operand = stoi(tokens[2]);

    encode_line(mem, command, operand);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "First argument should be the path!" << endl;
        return -1;
    }

    string file_path = argv[1];
    ifstream file(file_path);

    if (!file.is_open())
    {
        cout << "Error reading file..." << endl;
        return -1;
    }

    string line;
    while (getline(file, line))
    {
        size_t commentPos = line.find(';');
        if (commentPos != string::npos)
        {
            line = line.substr(0, commentPos);
        }
        if (!line.empty())
        {
            parse_line(line);
        }
    }

    std::ofstream outFile("memory.bin", std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < 128; i++)
    {
        outFile.write(reinterpret_cast<const char *>(&codes[i]), sizeof(codes[i]));
    }

    outFile.close();
    file.close();
    return 0;
}
