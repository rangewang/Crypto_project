import sys
import hashlib
from header_func import bin_to_header
from header_func import read_binary

def sha3_224_core(data):
    tmp = hashlib.sha3_224()
    tmp.update(data)
    result = tmp.hexdigest()
    return result

def sha3_256_core(data):
    tmp = hashlib.sha3_256()
    tmp.update(data)
    result = tmp.hexdigest()
    return result

def sha3_384_core(data):
    tmp = hashlib.sha3_384()
    tmp.update(data)
    result = tmp.hexdigest()
    return result

def sha3_512_core(data):
    tmp = hashlib.sha3_512()
    tmp.update(data)
    result = tmp.hexdigest()
    return result

def sha3_256_golden_test():
    test_input_empty = ""
    test_input_abc = "abc"
    test_input_448bit = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
    golden_ans_empty = "a7ffc6f8bf1ed76651c14756a061d662f580ff4de43b49fa82d80a4b80f8434a"
    golden_ans_abc = "3a985da74fe225b2045c172d6bd390bd855f086e3e9d525b46bfe24511431532"
    golden_ans_448bit = "41c0dba2a9d6240849100376a8235e2c82e1b9998a999e21db32dd97496d3376"
    print("Start sha3-256 golden test...")
    result = sha3_256_core(test_input_empty)
    print("input data : %s" %(test_input_empty))
    print("output : %s %s %s %s" %(result[0:16], result[16:32], result[32:48], result[48:64]))
    if (result == golden_ans_empty):
        print("=> golden data pass...")
    else:
        print("=> golden data fail...")

    result = sha3_256_core(test_input_abc)
    print("input data : %s" %(test_input_abc))
    print("output : %s %s %s %s" %(result[0:16], result[16:32], result[32:48], result[48:64]))
    if (result == golden_ans_abc):
        print("=> golden data pass...")
    else:
        print("=> golden data fail...")

    result = sha3_256_core(test_input_448bit)
    print("input data : %s" %(test_input_448bit))
    print("output : %s %s %s %s" %(result[0:16], result[16:32], result[32:48], result[48:64]))
    if (result == golden_ans_448bit):
        print("=> golden data pass...")
    else:
        print("=> golden data fail...")
    bin_to_header(test_input_448bit, result, "header.h")

def sha3_256_file(data_path):
    input_data = read_binary(data_path)
    print("input data : %s" %(input_data))
    result = sha3_256_core(input_data)
    print("output : %s %s %s %s" %(result[0:16], result[16:32], result[32:48], result[48:64]))
    bin_to_header(input_data, result, "header.h")
