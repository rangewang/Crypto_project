import sys
from hash_func import sha3_256_golden_test
from hash_func import sha3_256_file

if __name__ == "__main__":

    if (len(sys.argv) < 2):
        print(len(sys.argv))
        print("Usage: alg_name godlen/input_file [file_path]")
    else:
        if ((str(sys.argv[1]) == 'sha3-256') & (str(sys.argv[2]) == 'golden')):
            sha3_256_golden_test()
        elif ((str(sys.argv[1]) == 'sha3-256') & (str(sys.argv[2]) == 'file')):
            sha3_256_file(str(sys.argv[3]))