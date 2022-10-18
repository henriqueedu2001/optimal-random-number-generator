#include <bits/stdc++.h>

using namespace std;

/// @brief default seed used to the generation, if not specified
int DEFAULT_SEED = 2323;

/// @brief default multiplier used to the generation, if not specified
int DEFAULT_MULTIPLIER = 69; 

/// @brief default increment used to the generation, if not specified
int DEFAULT_INCREMENT = 13;

/// @brief default modulus used to the generation, if not specified
int DEFAULT_MODULUS = 29;

/// @brief simple linear congruential generator (LCG)
class SimpleLCGGenerator{
    public:
    int Seed;
    int Multiplier; 
    int Increment;
    int Modulus;

    /// @brief constructs the generator with all specified parameters
    /// @param seed 
    /// @param multiplier 
    /// @param increment 
    /// @param modulus 
    SimpleLCGGenerator(int seed, int multiplier, int increment, int modulus){
        Seed = seed;
        Multiplier = multiplier; 
        Increment = increment;
        Modulus = modulus;
    }

    /// @brief constructs the generator with default seed
    /// @param seed 
    /// @param multiplier 
    /// @param increment 
    /// @param modulus 
    SimpleLCGGenerator(int multiplier, int increment, int modulus){
        Seed = DEFAULT_SEED;
        Multiplier = multiplier; 
        Increment = increment;
        Modulus = modulus;
    }

    /// @brief constructs the generator with all default parameters
    /// @param seed 
    /// @param multiplier 
    /// @param increment 
    /// @param modulus 
    SimpleLCGGenerator(){
        Seed = DEFAULT_SEED;
        Multiplier = DEFAULT_MULTIPLIER; 
        Increment = DEFAULT_INCREMENT;
        Modulus = DEFAULT_MODULUS;
    }

    public:
    /// @brief returns a list with n = size pseudo-random numbers, using a linear congruential generator (LCG)
    /// @param size
    /// @return
    vector <int> GenerateList(int size){
        vector <int> new_list;

        // takes the previous element as a seed to generate the next — seed updating by the Generate() method
        for(int i = 0; i < size; i++)
            new_list.push_back(Generate(Seed));

        return new_list;
    }

    /// @brief returns a pseudo-random number, using a linear congruential generator (LCG)
    /// @param seed 
    /// @param multiplier 
    /// @param increment 
    /// @param modulus 
    /// @return
    public:
    int Generate(int seed){
        int new_number;
        new_number = ((seed * Multiplier) + Increment) % Modulus;
        Seed = new_number;
        return new_number;
    }

    /// @brief returns a pseudo-random number, using a linear congruential generator (LCG) (default seed)
    /// @param seed 
    /// @param multiplier 
    /// @param increment 
    /// @param modulus 
    /// @return
    public:
    int Generate(){
        int new_number;
        new_number = ((Seed * Multiplier) + Increment) % Modulus;
        Seed = new_number;
        return new_number;
    }
};