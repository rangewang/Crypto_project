import sys,time

def read_binary(file_path):
	fo = open(file_path, "rb")
	txt = fo.read()
	#print(txt)
	return txt

def bin_to_header(src_data, dst_data, file_path):
	src_data = src_data.decode()
	#dst_data = dst_data.decode()
	#print(src_data)
	#print(dst_data)

	fo = open(file_path, "w")
	str_text = ""
	str_text += "/*\n"
	str_text += " * ============================================ \n"
	str_text += " * Build at "
	str_text += time.asctime(time.localtime(time.time()))
	str_text += "\n"
	str_text += " * ============================================ \n"
	str_text += " */\n"
	str_text += "#ifndef " + (file_path.upper()).replace(".","_") + "\n"
	str_text += "#define " + (file_path.upper()).replace(".","_") + "\n\n"
	str_text += "unsigned char src_box[] = {\n"
	src_data_len = len(src_data)
	count = 0
	str_text += "    "
	for p in src_data:
		word = str(hex(ord(p)))
		str_text += " " + word
		if (count != (src_data_len-1)):
			str_text += ","
		count += 1
		if ((count % 16) == 0):
			str_text += "\n    "
	str_text += "\n};\n\n"

	str_text += "unsigned char dst_box[] = {\n"
	dst_data_len = len(dst_data)
	count = 0
	str_text += "    "
	while (count != dst_data_len):
		p = dst_data[count:count+2]
		str_text += " 0x" +  p
		if (count != (dst_data_len-2)):
			str_text += ","
		count += 2
		if ((count % 32) == 0):
			str_text += "\n    "
	str_text += "\n};\n"

	str_text += "#endif /* " + (file_path.upper()).replace(".","_") + " */"
	fo.write(str_text)
	fo.close()
	print("DONE")