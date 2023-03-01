#include "image_converter.h"

void convert_image_to_hex_array(string image_path, string output_file_path) {
    ifstream image_file(image_path, ios::binary);

    if (image_file) 
    {

        image_file.seekg(0, image_file.end);
        int size = image_file.tellg();
        image_file.seekg(0, image_file.beg);

        unsigned char* buffer = new unsigned char[size];
        image_file.read((char*)buffer, size);

        ofstream output_file(output_file_path);

        if (output_file) {
            output_file << "const unsigned char image[" << size << "] = {";

            for (int i = 0; i < size; i++) {
                output_file << "0x" << hex << (int)buffer[i];

                if (i != size - 1) {
                    output_file << ",";
                }
            }
            output_file << "};";
            output_file.close();
        }
        delete[] buffer;
    }
    image_file.close();
}
