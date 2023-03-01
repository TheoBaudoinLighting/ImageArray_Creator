#include "image_converter.h"

int main()
{
    string image_path;
    cout << "Welcome in TBM Image data converter !" << endl;
    cout << "Enter the name of the image to convert, this image must be in the folder with the converter" << endl;
    cin >> image_path;

    string output_file_path = image_path + ".txt";

    convert_image_to_hex_array(image_path, output_file_path);
    getchar();
    return 0;
}
