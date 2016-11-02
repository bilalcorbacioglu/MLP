//============================================================================
// Name : Main.cpp
// Author : David Nogueira
//============================================================================
#include "MLP.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "microunit.h"

UNIT(LearnAND) {
  std::cout << "Train AND function with mlp." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },{0.0}},
    {{ 0, 1 },{0.0}},
    {{ 1, 0 },{0.0}},
    {{ 1, 1 },{1.0}}
  };
  bool bias_already_in = false;
  std::vector<TrainingSample> training_sample_set_with_bias(training_set);
  //set up bias
  if (!bias_already_in) {
    for (auto & training_sample_with_bias : training_sample_set_with_bias) {
      training_sample_with_bias.AddBiasValue(1);
    }
  }

  size_t num_examples = training_sample_set_with_bias.size();
  size_t num_features = training_sample_set_with_bias[0].GetInputVectorSize();
  MLP my_mlp(num_features, 1, 0, 5, true, 0.5);
  //Train MLP
  my_mlp.UpdateMiniBatch(training_sample_set_with_bias, 2, 1000, 0.245);

  for (const auto & training_sample : training_sample_set_with_bias) {   
    std::vector<double>  output;
    my_mlp.GetOutput(training_sample.input_vector(), &output);
        bool predicted_output = output[0]> 0.5 ? true : false;
    bool correct_output = training_sample.output_vector()[0] > 0.5 ? true : false;
    ASSERT_TRUE(predicted_output == correct_output);
  }
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnNAND) {
  std::cout << "Train NAND function with mlp." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },{1.0}},
    {{ 0, 1 },{1.0}},
    {{ 1, 0 },{1.0}},
    {{ 1, 1 },{0.0}}
  };
  bool bias_already_in = false;
  std::vector<TrainingSample> training_sample_set_with_bias(training_set);
  //set up bias
  if (!bias_already_in) {
    for (auto & training_sample_with_bias : training_sample_set_with_bias) {
      training_sample_with_bias.AddBiasValue(1);
    }
  }

  size_t num_examples = training_sample_set_with_bias.size();
  size_t num_features = training_sample_set_with_bias[0].GetInputVectorSize();
  MLP my_mlp(num_features, 1, 0, 5, true, 0.5);
  //Train MLP
  my_mlp.UpdateMiniBatch(training_sample_set_with_bias, 2, 1000, 0.245);

  for (const auto & training_sample : training_sample_set_with_bias) {
    std::vector<double>  output;
    my_mlp.GetOutput(training_sample.input_vector(), &output);
        bool predicted_output = output[0]> 0.5 ? true : false;
    bool correct_output = training_sample.output_vector()[0] > 0.5 ? true : false;
    ASSERT_TRUE(predicted_output == correct_output);
  }
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnOR) {
  std::cout << "Train OR function with mlp." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },{0.0}},
    {{ 0, 1 },{1.0}},
    {{ 1, 0 },{1.0}},
    {{ 1, 1 },{1.0}}
  };
  bool bias_already_in = false;
  std::vector<TrainingSample> training_sample_set_with_bias(training_set);
  //set up bias
  if (!bias_already_in) {
    for (auto & training_sample_with_bias : training_sample_set_with_bias) {
      training_sample_with_bias.AddBiasValue(1);
    }
  }

  size_t num_examples = training_sample_set_with_bias.size();
  size_t num_features = training_sample_set_with_bias[0].GetInputVectorSize();
  MLP my_mlp(num_features, 1, 0, 5, true, 0.5);
  //Train MLP
  my_mlp.UpdateMiniBatch(training_sample_set_with_bias, 2, 1000, 0.245);

  for (const auto & training_sample : training_sample_set_with_bias) {
    std::vector<double>  output;
    my_mlp.GetOutput(training_sample.input_vector(), &output);
        bool predicted_output = output[0]> 0.5 ? true : false;
    bool correct_output = training_sample.output_vector()[0] > 0.5 ? true : false;
    ASSERT_TRUE(predicted_output == correct_output);
  }
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnNOR) {
  std::cout << "Train NOR function with mlp." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },{1.0}},
    {{ 0, 1 },{0.0}},
    {{ 1, 0 },{0.0}},
    {{ 1, 1 },{0.0}}
  };
  bool bias_already_in = false;
  std::vector<TrainingSample> training_sample_set_with_bias(training_set);
  //set up bias
  if (!bias_already_in) {
    for (auto & training_sample_with_bias : training_sample_set_with_bias) {
      training_sample_with_bias.AddBiasValue(1);
    }
  }

  size_t num_examples = training_sample_set_with_bias.size();
  size_t num_features = training_sample_set_with_bias[0].GetInputVectorSize();
  MLP my_mlp(num_features, 1, 0, 5, true, 0.5);
  //Train MLP
  my_mlp.UpdateMiniBatch(training_sample_set_with_bias, 2, 1000, 0.245);

  for (const auto & training_sample : training_sample_set_with_bias) {
    std::vector<double>  output;
    my_mlp.GetOutput(training_sample.input_vector(), &output);
        bool predicted_output = output[0]> 0.5 ? true : false;
    bool correct_output = training_sample.output_vector()[0] > 0.5 ? true : false;
    ASSERT_TRUE(predicted_output == correct_output);
  }
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

//UNIT(LearnXOR) {
//  std::cout << "Train XOR function with mlp." << std::endl;
//
//  std::vector<TrainingSample> training_set =
//  {
//    { { 0, 0 },{ 0.0 } },
//    { { 0, 1 },{ 1.0 } },
//    { { 1, 0 },{ 1.0 } },
//    { { 1, 1 },{ 0.0 } }
//  };
//  bool bias_already_in = false;
//  std::vector<TrainingSample> training_sample_set_with_bias(training_set);
//  //set up bias
//  if (!bias_already_in) {
//    for (auto & training_sample_with_bias : training_sample_set_with_bias) {
//      training_sample_with_bias.AddBiasValue(1);
//    }
//  }
//
//  size_t num_examples = training_sample_set_with_bias.size();
//  size_t num_features = training_sample_set_with_bias[0].GetInputVectorSize();
//  MLP my_mlp(num_features, 1, 0, 5, true, 0.5);
//  //Train MLP
//  my_mlp.UpdateMiniBatch(training_sample_set_with_bias, 2, 1000, 0.245);
//
//  for (const auto & training_sample : training_sample_set_with_bias) {
//    std::vector<double>  output;
//    my_mlp.GetOutput(training_sample.input_vector(), &output);
//        bool predicted_output = output[0]> 0.5 ? true : false;
//    bool correct_output = training_sample.output_vector()[0] > 0.5 ? true : false;
//    ASSERT_TRUE(predicted_output == correct_output);
//  }
//  std::cout << "Trained with success." << std::endl;
//  std::cout << std::endl;
//}

UNIT(LearnNOT) {
  std::cout << "Train NOT function with mlp." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0},{1.0 }},
    {{ 1},{0.0 }}
  };
  bool bias_already_in = false;
  std::vector<TrainingSample> training_sample_set_with_bias(training_set);
  //set up bias
  if (!bias_already_in) {
    for (auto & training_sample_with_bias : training_sample_set_with_bias) {
      training_sample_with_bias.AddBiasValue(1);
    }
  }

  size_t num_examples = training_sample_set_with_bias.size();
  size_t num_features = training_sample_set_with_bias[0].GetInputVectorSize();
  MLP my_mlp(num_features, 1, 0, 5, true, 0.5);
  //Train MLP
  my_mlp.UpdateMiniBatch(training_sample_set_with_bias, 2, 1000, 0.245);

  for (const auto & training_sample : training_sample_set_with_bias) {
    std::vector<double>  output;
    my_mlp.GetOutput(training_sample.input_vector(), &output);
        bool predicted_output = output[0]> 0.5 ? true : false;
    bool correct_output = training_sample.output_vector()[0] > 0.5 ? true : false;
    ASSERT_TRUE(predicted_output == correct_output);
  }
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

int main() {
  microunit::UnitTester::Run();
  return 0;
}