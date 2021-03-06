/*
 *  Copyright (c) 2018-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace fizz {
namespace tool {

int fizzClientCommand(const std::vector<std::string>& args);
int fizzServerCommand(const std::vector<std::string>& args);
int fizzGenerateDelegatedCredentialCommand(
    const std::vector<std::string>& args);
const std::vector<std::string> utilityNames = {"client",
                                               "s_client",
                                               "server",
                                               "s_server",
                                               "gendc"};

const std::map<std::string, std::function<int(const std::vector<std::string>&)>>
    fizzUtilities = {{"client", &fizzClientCommand},
                     {"s_client", &fizzClientCommand},
                     {"server", &fizzServerCommand},
                     {"s_server", &fizzServerCommand},
                     {"gendc", &fizzGenerateDelegatedCredentialCommand}};

const std::map<std::string, std::string> utilityDescriptions = {
    {"client", "TLS 1.3 client"},
    {"s_client", "Alias for client"},
    {"server", "TLS 1.3 server"},
    {"s_server", "Alias for server"},
    {"gendc", "Generate a delegated credential"}};
} // namespace tool
} // namespace fizz
