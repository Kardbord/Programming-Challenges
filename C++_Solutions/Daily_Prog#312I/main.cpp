#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

// Function Prototypes
bool init_inputs(int const &argc, char *argv[], std::vector<std::string> &inputs);
std::string compute_next_largest(std::string const &input);
void swap(std::string &container, int const &index1, int const &index2);
bool validateInput(std::string const &input);
// END Function Prototypes

// MAIN
int main(int argc, char *argv[]) {
    std::vector<std::string> inputs;
    if (!init_inputs(argc, argv, inputs)) return EXIT_FAILURE;

    if (inputs.size() != 0) {
        for (auto &&number : inputs) {
            std::cout << number << " ---> " << compute_next_largest(number) << std::endl;
        }
    }

    // TODO: ask for user input

    return EXIT_SUCCESS;
} // END MAIN

bool init_inputs(int const &argc, char *argv[], std::vector<std::string> &inputs) {
    if (argc > 2) {
        std::cerr << "Too many command line arguments provided -- expected 0 or 1" << std::endl;
        return false;
    }

    // if no cmd line args provided
    if (argc < 2) return true;

    // if input file provided
    std::ifstream fin(argv[1]);
    if (!fin.is_open()) {
        std::cerr << "Error opening " << argv[1] << ", program terminated" << std::endl;
        return false;
    }

    // read in file
    std::string input = "";
    for (int i = 0; fin >> input; ++i) {
        inputs.push_back(input);
        if (!validateInput(inputs[i])) {
            return false;
        }
    }
    fin.close();
    return true;
}

/**
 * Computes the next largest number using only the digits available
 *
 * @param input
 * @return next largest number using only the digits contained in 'input'
 */
std::string compute_next_largest(std::string const &input) {

    // check that the number does not consist of identical digits
    if (input.find_first_not_of(input[0]) == std::string::npos) return input;

    std::string nextLargest = input;

    /*
     * Yes, I know this is confusing, but it's cool dang it.
     * The for loop contains an anonymous struct so I can initialize variables of multiple types for use in the loop
     * See http://stackoverflow.com/questions/11255684/why-c-does-not-support-multiple-initializers-in-for-loop
     */
    for (struct { int index; bool swapped, out_of_bounds; } loopVars = {(int) nextLargest.size() - 1, false, false};
         !loopVars.swapped && !loopVars.out_of_bounds; --loopVars.index) {
        // if we've reached the second-to-most-significant digit, then either we can swap it or we're out of range
        if (loopVars.index <= 1) loopVars.out_of_bounds = true;
        for (int j = 1; !loopVars.swapped && j <= loopVars.index; ++j) {

            if (nextLargest[loopVars.index] != '0') {
                if (nextLargest[loopVars.index] > nextLargest[loopVars.index - j]) {
                    swap(nextLargest, loopVars.index, loopVars.index - j);
                    loopVars.swapped = true;
                    std::sort(nextLargest.begin() + (loopVars.index - j) + 1, nextLargest.end());
                }
            }
        }
    }

    return nextLargest;
}

void swap(std::string &container, int const &index1, int const &index2) {
    auto temp = container[index1];
    container[index1] = container[index2];
    container[index2] = temp;
}

bool validateInput(std::string const &input) {
    if (input[0] == '-') {
        std::cerr << "Error! Negative input value present, program terminated." << std::endl;
        return false;
    }

    if (input.find('.') != std::string::npos) {
        std::cerr << "Error! Non-whole number input present, program terminated." << std::endl;
        return false;
    }

    if (input.find_first_not_of("0123456789") != std::string::npos) {
        std::cerr << "Error! Non-numeric input present, program terminated." << std::endl;
        return false;
    }

    return true;
}


