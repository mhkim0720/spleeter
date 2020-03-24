///
/// @file
/// @copyright Copyright (c) 2020, MIT License
///
#ifndef SPLEETER_INFERENCE_ENGINE_TF_INFERENCE_ENGINE_H_
#define SPLEETER_INFERENCE_ENGINE_TF_INFERENCE_ENGINE_H_

#include "spleeter/argument_parser/cli_options.h"
#include "spleeter/inference_engine/i_inference_engine.h"

#include "tensorflow/cc/client/client_session.h"
#include "tensorflow/cc/saved_model/loader.h"

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace spleeter
{
/// @brief TensorFlow Inference Engine class
class TFInferenceEngine : public IInferenceEngine
{
  public:
    /// @brief Default Constructor
    TFInferenceEngine();

    /// @brief Constructor
    /// @param cli_options [in] - Command Line Interface Options
    explicit TFInferenceEngine(const CLIOptions& cli_options);

    /// @brief Destructor
    ~TFInferenceEngine() = default;

    /// @brief Initialise TensorFlow Inference Engine
    void Init() override;

    /// @brief Execute Inference with TensorFlow Inference Engine
    void Execute() override;

    /// @brief Release TensorFlow Inference Engine
    void Shutdown() override;

    /// @brief Set input data (waveform)
    /// @param waveform [in] - Waveform to be split
    void SetInputWaveform(const Waveform& waveform) override;

    /// @brief Obtain Results for provided input waveform
    /// @return List of waveforms (split waveforms)
    Waveforms GetResults() const override;

  private:
    /// @brief Invokes Inference with TensorFlow APIs
    /// @return List of waveforms (split waveforms)
    virtual Waveforms InvokeInference() const;

    /// @brief Extracts model path from the provided command line arguments
    virtual std::string GetModelPath() const;

    /// @brief Provide more detail logging
    virtual bool IsVerbosityEnabled() const;

    /// @brief Command Line Options
    CLIOptions cli_options_;

    /// @brief Inference results (waveforms)
    Waveforms results_;

    /// @brief Saved Model bundle
    std::shared_ptr<tensorflow::SavedModelBundle> bundle_;

    /// @brief Input Tensor
    tensorflow::Tensor input_tensor_;

    /// @brief Output Tensors
    std::vector<tensorflow::Tensor> output_tensors_;

    /// @brief Output Tensors names
    std::vector<std::string> output_tensor_names_;

    /// @brief Model root directory
    const std::string model_dir_;
};

}  // namespace spleeter
#endif  /// SPLEETER_INFERENCE_ENGINE_TF_INFERENCE_ENGINE_H_
