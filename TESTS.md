./pipex infile "date +%H:%M:%S" "cat" outfile -> 12:20:11
./pipex infile "ls -l" "wc -l" outfile -> Lista los archivos de infile, redirige la salida a wc -l y guarda el resultado en outfile.
./pipex infile "cat" "grep de" outfile -> Usa cat para mostrar el contenido de infile, filtra las líneas que contienen "text" con grep, y guarda el resultado en outfile
./pipex infile "head -n 3" "rev" outfile -> Toma las primeras 3 líneas de infile y las invierte con rev.
# Comandos de errores
./pipex nofile "ls -l" "wc -l" outfile -> Error: El archivo de entrada nofile no existe.
./pipex infile "invalidcmd" "wc -l" outfile -> Error: El comando invalidcmd no es válido.
./pipex infile "ls -l" "invalidcmd" outfile -> Error: El segundo comando es inválido.
./pipex infile "" "wc -l" outfile -> Error: El primer comando está vacío.
# Comandos especiales
./pipex infile "echo hola" "tr a-z A-Z" outfile -> Convierte la palabra "hola" en mayúsculas y guarda el resultado en outfile
./pipex /dev/null "echo test" "cat" outfile -> Prueba con un archivo de entrada vacío (/dev/null). El resultado debería ser un archivo vacío o solo contener la salida de los comandos.
./pipex infile "sort" "uniq" outfile -> Ordena el contenido de infile y elimina las líneas duplicadas.
# Comandos sin permisos
./pipex infile "echo test" "cat" no_write_file -> no_write_file: Permission denied
./pipex no_read_file "cat" "wc -l" outfile NO ME FUNCIONA PORQUE NO QUITA PERMISOS CORRECTAMENTE!!
./pipex /etc/shadow "cat" "wc -l" outfile (Para permisos de lectura)
