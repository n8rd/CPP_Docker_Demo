#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to split a string into tokens based on a delimiter
vector<string> split(string line, char delimiter) {
  vector<string> tokens;
  string token;

  for (char c : line) {
    if (c == delimiter) {
      tokens.push_back(token);
      token = "";
    } else {
      token += c;
    }
  }

  tokens.push_back(token);

  return tokens;
}

int main(int argc, char** argv) {
  // Check if the user has provided a delimiter
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <filename> <delimiter>" << endl;
    return 1;
  }

  // Get the filename and delimiter from the command line arguments
  string filename = argv[1];
  filename="/app/data/"+ filename;
  cout << "Filename : " << filename << endl;
  char delimiter = argv[2][0];
  cout << "delimiter : " << delimiter << endl;  

  // Open the CSV file
  ifstream myfile(filename);

  // Check if the file is open
  if (!myfile.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  // Read the file line by line
  string line;
  while (getline(myfile, line)) {
    // Split the line into tokens based on the delimiter
    vector<string> tokens = split(line, delimiter);

    // Print the tokens
    for (string token : tokens) {
      cout << token << " ";
    }
    cout << endl;
  }

  // Close the file
  myfile.close();

  return 0;
}