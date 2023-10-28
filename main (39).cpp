#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    std::string sourceFilePath, destinationFilePath;
    off_t sourceOffset, destinationOffset;
    size_t numBytes;
    std::cout << "Enter the name of the source file: ";
    std::cin >> sourceFilePath;
    std::cout << "Enter the name of the destination file: ";
    std::cin >> destinationFilePath;
    std::cout << "Enter the initial offset in the source file (in bytes): ";
    std::cin >> sourceOffset;
    std::cout << "Enter the initial offset in the destination file (in bytes): ";
    std::cin >> destinationOffset;
    std::cout << "Enter the number of bytes to copy: ";
    std::cin >> numBytes;
    int sourceFile = open(sourceFilePath.c_str(), O_RDONLY);
    if (sourceFile == -1)
    {
        perror("Failed");
        return 1;
    }
    int destinationFile = open(destinationFilePath.c_str(), O_WRONLY);
    if (destinationFile == -1)
    {
        close(sourceFile);
        perror("Failed");
        return 1;
    }
    if (lseek(sourceFile, sourceOffset, SEEK_SET) == -1)
    {
        close(sourceFile);
        close(destinationFile);
        perror("Failed");
        return 1;
    }
    if (lseek(destinationFile, destinationOffset, SEEK_SET) == -1)
    {
        close(sourceFile);
        close(destinationFile);
        perror("Failed");
        return 1;
    }
    char buffer[BUFSIZ];
    ssize_t bytesRead, bytesWritten;
    while (numBytes > 0)
    {
        size_t chunkSize = std::min(numBytes, sizeof(buffer));
        bytesRead = read(sourceFile, buffer, chunkSize);
        if (bytesRead == -1)
        {
            close(sourceFile);
            close(destinationFile);
            perror("Failed");
            return 1;
        } 
        else if (bytesRead == 0)
        {
            break; 
        }
        bytesWritten = write(destinationFile, buffer, bytesRead);
        if (bytesWritten == -1)
        {
            close(sourceFile);
            close(destinationFile);
            perror("Failed");
            return 1;
        }
        numBytes -= bytesWritten;
    }
    close(sourceFile);
    close(destinationFile);
    std::cout << "Successfully copied " << numBytes << " bytes from the source file to the destination file.\n";
    return 0;
}