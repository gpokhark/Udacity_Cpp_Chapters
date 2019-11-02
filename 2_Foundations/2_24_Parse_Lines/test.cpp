void PrintVector(std::vector<int> v) {
  std::cout << "{ ";
  for (auto item : v) {
    std::cout << item << " ";
  }
  std::cout << "}" << "\n";
}

void TestParseLine() {
  std::cout << "----------------------------------------------------------" << "\n";
  std::cout << "TestParseLine: ";
  std::string line = "0,1,0,0,0,0,";
  std::vector<int> solution_vect{0,1,0,0,0,0};
  std::vector<int> test_vect;
  test_vect = ParseLine(line);
  if (test_vect != solution_vect) {
    std::cout << "failed" << "\n";
    std::cout << "\n" << "Test input string: " << line << "\n";
    std::cout << "Your parsed line: ";
    PrintVector(test_vect);
    std::cout << "\n";
  } else {
    std::cout << "passed" << "\n";
  }
  std::cout << "----------------------------------------------------------" << "\n";
  return;
}