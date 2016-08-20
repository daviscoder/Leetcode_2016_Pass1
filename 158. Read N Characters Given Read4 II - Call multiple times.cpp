// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buf4[4] = {0};
    int offSet = 0;
    int bufSize = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while (ptr < n) {
            if (offSet == 0) {
                bufSize = read4 (buf4);
            }
            if (bufSize == 0) break;
            while (ptr < n && offSet < bufSize) {
                buf[ptr] = buf4[offSet];
                offSet++;
                ptr++;
            }
            if (offSet == bufSize)
                offSet = 0;
        }
        return ptr;
    }
};
