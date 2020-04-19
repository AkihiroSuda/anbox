/*
 * Copyright (C) 2020 NTT Corporation
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <iterator>
#include "anbox/qemu/tee_message_processor.h"
#include "anbox/logger.h"
#include "anbox/utils.h"

namespace anbox {
namespace qemu {
TeeMessageProcessor::TeeMessageProcessor(const std::shared_ptr<network::MessageProcessor> &processor, const std::shared_ptr<std::ostream> &out)
    : processor_(processor), out_(out) {
}

TeeMessageProcessor::~TeeMessageProcessor() {}

bool TeeMessageProcessor::process_data(const std::vector<std::uint8_t> &data) {
  auto stream = out_.get();
  std::ostream_iterator<uint8_t> it(*stream);
  std::copy(data.begin(), data.end(), it);
  return processor_.get()->process_data(data);
}
}  // namespace qemu
}  // namespace anbox
