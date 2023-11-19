
int main() {
    int line = 0;
    scanf("%d", &line);

    for (int i = 0; i < line; i++) {
        int bytes = 0;
        scanf("%d", &bytes);

        int value = 0;
        int value_remain = 0;
        int length = 0;
        int length_remain = 5;
        int sign = 0;
        for (int j = 0; j < bytes; j++) {
            int bytes_remain = 8;
            int byte = 0;
            scanf("%d", byte);
            if (length_remain > 0) {
                // For length
                bytes_combine(&length, &length_remain, byte, &bytes_remain);
                value_remain = length;
            }

            // For sign
            if (value_remain == length) {
                // Read sign
                sign = (byte >> (bytes_remain-1)) & 1;
                bytes_remain--;
                value_remain--;
            }

            // For value
            bytes_combine(&value, &value_remain, byte, &bytes_remain);

            // If value finished
            if (value_remain == 0) {
                printf("%d\n", value);
                value = 0;
                length_remain = 5;
            }
            // If bytes finished
            if (bytes_remain == 0) {
                continue;
            }

            // For length
            bytes_combine(&length, &length_remain, byte, &bytes_remain);
            if (length_remain == 0) {
                value_remain = length;
            } else {
                continue;
            }

            // For sign
            if (bytes_remain > 0) {
                // Read sign
                sign = (byte >> (bytes_remain-1)) & 1;
                bytes_remain--;
            }
            // For value
            if (bytes_remain > 0) {
                bytes_combine(&value, &value_remain, byte, &bytes_remain);
            }

            // Other bytes finished, continue;

        }
    }
}

void bytes_combine(int* target, int *target_vacancy, int source, int *source_vacancy) {
    if (*target_vacancy > *source_vacancy) {
        int piece = source & ((1 << (*source_vacancy)) -1);
        *target_vacancy = *target_vacancy - *source_vacancy;
        *source_vacancy = 0;
        *target = *target | (piece << (*target_vacancy));
    } else {
        int piece = (source << *target_vacancy) & ((1 << *target_vacancy)-1);
        *source_vacancy = *source_vacancy - *target_vacancy;
        *target_vacancy = 0;
        *target = *target | piece;
    }
}