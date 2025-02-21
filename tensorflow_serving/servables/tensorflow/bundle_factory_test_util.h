/* Copyright 2016 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_BUNDLE_FACTORY_TEST_UTIL_H_
#define TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_BUNDLE_FACTORY_TEST_UTIL_H_

#include <gtest/gtest.h>
#include "tensorflow/core/protobuf/meta_graph.pb.h"
#include "tensorflow/core/public/session.h"
#include "tensorflow_serving/resources/resources.pb.h"

namespace tensorflow {
namespace serving {
namespace test_util {

// Returns the path of the Saved Model (the pb version) for the half plus two
// model.
string GetTestSavedModelPath();
string GetTestMLMetadataSavedModelPath();

// Returns the Session Bundle export path for the half plus two model.
string GetTestSessionBundleExportPath();

// Returns the path of TensorFlow Lite model for the half plus two model.
string GetTestTfLiteModelPath();

// Returns the paths of the files of the Session Bundle export for the half plus
// two model.
std::vector<string> GetTestSessionBundleExportFiles();

// Returns the paths of the files of the SavedModel Bundle export for the half
// plus two model.
std::vector<string> GetTestSavedModelBundleExportFiles();

// Returns the total size of the given files. Requires the files to exist.
uint64_t GetTotalFileSize(const std::vector<string>& files);

// Returns a signature for the half plus two model.
SignatureDef GetTestSessionSignature();

// Test that a Session handles a single request for the half plus two
// model properly. Each request contains `input_batch_size` sized input.
void TestSingleRequest(Session* session, int input_batch_size = 2);

// Test that a Session handles multiple concurrent requests for the half plus
// two model properly. Send `num_requests` request, with each request containing
// `input_batch_size` sized input.
void TestMultipleRequests(Session* session, int num_requests,
                          int input_batch_size);

// Returns the expected resource estimate for the given total file size.
ResourceAllocation GetExpectedResourceEstimate(double total_file_size);

}  // namespace test_util
}  // namespace serving
}  // namespace tensorflow

#endif  // TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_BUNDLE_FACTORY_TEST_UTIL_H_
