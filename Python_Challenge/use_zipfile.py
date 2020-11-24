import use_zipfile

txt_to_zip = 'asdf.txt'
zip_path = r'C:\Users\jungm\Desktop\GitHub\Study_in_school\Python_Challenge\asdf.zip'

my_zip = use_zipfile.ZipFile(zip_path, 'w')
my_zip.write(txt_to_zip, compress_type=use_zipfile.ZIP_DEFLATED)

my_zip.close()

# -------------------

zip_path = r'C:\Users\jungm\Desktop\GitHub\Study_in_school\Python_Challenge\asdf.zip'
name_to_extract = 're_asdf'
my_zip = use_zipfile.ZipFile(zip_path)
my_zip.extractall(name_to_extract)

my_zip.close()
