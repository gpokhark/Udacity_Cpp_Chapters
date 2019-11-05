#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    // create strings in the hash table
    std::string key = "word";
    std::string def_1 = "a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
    std::string def_2 = "speech or talk: to express one's emotion in words";
    std::string def_3 = "a short talk or conversation: 'Marston, I'd like a word with you.'";
    std::string def_4 = "an expression or utterance: a word of warning";
    std::unordered_map<std::string, std::vector<std::string>> my_dictionary;

    //check if the key is in the hash table
    if (my_dictionary.find(key) == my_dictionary.end())
    {
        std::cout << "The key 'word' is not in the dictionary."
                  << "\n";
        std::cout << "Inserting a key-value pair into the dictionary."
                  << "\n\n";
        // Set the value for the key.
        my_dictionary[key] = std::vector<std::string> { def_1, def_2, def_3, def_4 };
    }

    // The key should now be in the hash table. You can access the
    // value corresponding to the key with square brackets [].
    // Here, the value my_dictionary[key] is a vector of strings.
    // We iterate over the vector and print the strings.
    std::cout << key << ": \n";
    auto definitions = my_dictionary[key];
    for (std::string definition : definitions)
    {
        std::cout << definition << "\n";
    }

    return 0;
}
