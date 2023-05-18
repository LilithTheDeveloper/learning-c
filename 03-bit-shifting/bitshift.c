#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include <stdint.h>
#include <stdbool.h>


/// @brief Decode a uint16_t from a buffer
/// @param buffer Pointer to the buffer containing the bytes to be decoded
/// @param data Pointer to the uint16_t to be fill
/// @return Number of bytes read from the buffer
int decode_uint16(uint8_t* buffer, uint16_t* data)
{
    *data = (uint16_t)buffer[0] << 8 | buffer[1];
    return 2;
}

int main() {
    uint8_t buffer[] = {0x0A, 0x0F, 0x0B, 0x0C};
    uint16_t data = 0;
    
    printf("%02x\n", buffer[0]);
    printf("%02x\n", buffer[1]);
    printf("%02x\n", buffer[2]);
    printf("%02x\n", buffer[3]);
    
    //We pass the pointer to the buffer at the third position and the pointer to the data to be filled.
    //The function will fill the data and return the number of bytes read from the buffer.
    //In this way we can combine multiple bytes of data from the buffer into a single variable.
    
    //buffer[2] is 0x0B and buffer[3] is 0x0C
    //When we now pass the pointer to buffer[2] the function can shift from then on the bytes to the left so that the first byte is 0x0B and the second byte is 0x0C in the data variable.
    decode_uint16(&buffer[2], &data);
    //data = 0x0B0C
    
    printf("%04x\n", data);

    
    return 0;
}