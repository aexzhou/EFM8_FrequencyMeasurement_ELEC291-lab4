@echo off
::This file was created automatically by CrossIDE to compile with C51.
C:
cd "\Users\cosr3\Documents\GitHub\ELEC-291-Lab4\"
"C:\CrossIDE\Call51\Bin\c51.exe" --use-stdout  "C:\Users\cosr3\Documents\GitHub\ELEC-291-Lab4\Lab4.c"
if not exist hex2mif.exe goto done
if exist Lab4.ihx hex2mif Lab4.ihx
if exist Lab4.hex hex2mif Lab4.hex
:done
echo done
echo Crosside_Action Set_Hex_File C:\Users\cosr3\Documents\GitHub\ELEC-291-Lab4\Lab4.hex
