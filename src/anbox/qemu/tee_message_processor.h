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

#ifndef ANBOX_QEMU_TEE_MESSAGE_PROCESSOR_H_
#define ANBOX_QEMU_TEE_MESSAGE_PROCESSOR_H_

#include <memory>
#include "anbox/network/message_processor.h"

namespace anbox {
namespace qemu {
class TeeMessageProcessor : public network::MessageProcessor {
 public:
  TeeMessageProcessor(const std::shared_ptr<network::MessageProcessor> &processor, const std::shared_ptr<std::ostream> &out);
  ~TeeMessageProcessor();

  bool process_data(const std::vector<std::uint8_t> &data) override;
 private:
  std::shared_ptr<network::MessageProcessor> processor_;
  std::shared_ptr<std::ostream> out_;
};
}  // namespace qemu
}  // namespace anbox

#endif
