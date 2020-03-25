///
/// @file
/// @copyright Copyright (c) 2020, MIT License
///
#include "spleeter/audio/ffmpeg_audio_adapter.h"
#include "spleeter/audio/i_audio_adapter.h"
#include "spleeter/logging/logging.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <fstream>
#include <memory>

namespace spleeter
{
namespace
{
class AudioAdapterTest : public ::testing::Test
{
  public:
    AudioAdapterTest()
        : audio_adapter_{std::make_unique<FfmpegAudioAdapter>()},
          test_audio_description_{"external/audio_example/file/audio_example.wav"},
          test_offset_{0.0},
          test_duration_{600.0},
          test_sample_rate_{44100},
          test_codec_{"mp3"},
          test_bitrate_{"128k"}
    {
    }

    ~AudioAdapterTest() = default;

  protected:
    std::unique_ptr<IAudioAdapter> audio_adapter_;

    const std::string test_audio_description_;
    const double test_offset_;
    const double test_duration_;
    const std::int32_t test_sample_rate_;
    const std::string test_codec_;
    const std::string test_bitrate_;
};

TEST_F(AudioAdapterTest, DISABLED_Load)
{
    auto waveform_sample_rate_pair =
        audio_adapter_->Load(test_audio_description_, test_offset_, test_duration_, test_sample_rate_);

    // auto waveform = waveform_sample_rate_pair.first;
    // auto sample_rate = waveform_sample_rate_pair.second;

    // ASSERT_EQ(sample_rate, test_sample_rate_);
    // ASSERT_FALSE(waveform.empty());
    // ASSERT_EQ(waveform.size(), 2);
    // ASSERT_EQ(waveform[0].size(), 479832);
    // ASSERT_EQ(waveform[1].size(), 2);
}

TEST_F(AudioAdapterTest, DISABLED_LoadError)
{
    EXPECT_EXIT(audio_adapter_->Load("Paris City Jazz", test_offset_, test_duration_, test_sample_rate_),
                ::testing::KilledBySignal(SIGABRT), "");
}

TEST_F(AudioAdapterTest, DISABLED_Save)
{
    // std::string path = "/tmp/decoded_audio.mp3";
    // auto codec = "mp3";
    // auto bitrate = 128000;
    // auto sample_rate = 44100;
    // std::ifstream audio_file("/tmp/decoded_audio.pcm");
    // ASSERT_CHECK(audio_file.is_open()) << "Failed to open test file";
    // // std::string audio_data{std::istream_iterator<std::uint8_t>(audio_file),
    // std::istream_iterator<std::uint8_t>()};
    // // SPLEETER_LOG(INFO) << "Read {" << (audio_data.size() / 1000) << "} Kbytes.";

    // // audio_adapter_->Save(path, audio_data, sample_rate, codec, bitrate);
}

}  // namespace
}  // namespace spleeter