In this example, the open() function is used to open the file "example.txt" in read-only mode. The O_RDONLY constant is used to specify the mode. If the file couldn't be opened, the perror() function is used to print an error message along with the reason for the failure.

Similarly, other flags can be used with the open() function to specify different modes such as write, append, or read/write. Here are some commonly used flags:

    O_RDONLY: Read-only mode.
    O_WRONLY: Write-only mode.
    O_RDWR: Read and write mode.
    O_CREAT: Create the file if it doesn't exist.
    O_APPEND: Append data to the end of the file.
    O_TRUNC: Truncate the file if it already exists.


O_TRUNC:
--------
The constant O_TRUNC is a flag used with the open() function in C to specify that if the file being opened already exists, its contents should be truncated (emptied) before writing new data to it. In other words, if the file exists and you open it with the O_TRUNC flag, the existing data will be removed, and the file will become empty.

// Open a file for writing, and if it exists, truncate its contents

fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);


// comprobar si es builtin o no
                if (is_builtin)
                {
                    exec_builtin();
                }
                else
                {
                    execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
                }