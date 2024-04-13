#include <gtest/gtest.h>

#include "../model.h"

using namespace MyNamespace;

TEST(SmartCalcTests, Test_1) {
  Model m;
  std::string expression = "sin(45)/(log(13.2) mod ln(3.88))";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_NEAR(result, 0.759346, 1e-6);
}

TEST(SmartCalcTests, Test_2) {
  Model m;
  std::string expression = "(2+2))";
  ASSERT_ANY_THROW(m.calculateValue(expression, 0));
}

TEST(SmartCalcTests, Test_3) {
  Model m;
  std::string expression = "2+";
  ASSERT_ANY_THROW(m.calculateValue(expression, 0));
}

TEST(SmartCalcTests, Test_4) {
  Model m;
  std::string expression = "()";
  ASSERT_ANY_THROW(m.calculateValue(expression, 0));
}

TEST(SmartCalcTests, Test_5) {
  Model m;
  std::string expression = "100//10";
  ASSERT_ANY_THROW(m.calculateValue(expression, 0));
}

TEST(SmartCalcTests, Test_6) {
  Model m;
  std::string expression = "100а + 123";
  ASSERT_ANY_THROW(m.calculateValue(expression, 0));
}

TEST(SmartCalcTests, Test_7) {
  Model m;
  std::string expression = "12e / 10";
  ASSERT_ANY_THROW(m.calculateValue(expression, 0));
}

TEST(SmartCalcTests, Test_8) {
  Model m;
  std::string expression = "1e-2";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_NEAR(result, 0.01, 1e-6);
}

TEST(SmartCalcTests, Test_9) {
  Model m;
  std::string expression = "2^2^3";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_NEAR(result, 256, 1e-6);
}

TEST(SmartCalcTests, Test_10) {
  Model m;
  std::string expression = "100 / 0";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_TRUE(isinf(result));
}

TEST(SmartCalcTests, Test_11) {
  Model m;
  std::string expression = "0 / 0";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_TRUE(isnan(result));
}

TEST(SmartCalcTests, Test_12) {
  Model m;
  std::string expression = "sqrt(423.2 ^ 0.42 * 3)";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_NEAR(result, 6.16787, 1e-6);
}

TEST(SmartCalcTests, Test_13) {
  Model m;
  std::string expression = "-2-(-4)";
  m.calculateValue(expression, 0);
  double result = m.getResult();
  ASSERT_NEAR(result, 2, 1e-6);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
