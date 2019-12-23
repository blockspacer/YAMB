///
//
// LibSourcey
// Copyright (c) 2005, Sourcey <https://sourcey.com>
//
// SPDX-License-Identifier: LGPL-2.1+
//
/// @addtogroup turn
/// @{


#ifndef SCY_TURN_UDPClient_H
#define SCY_TURN_UDPClient_H


#include "../../net/udpsocket.h"
#include "../../base/stateful.h"
#include "../../stun/transaction.h"
#include "client.h"
#include "../iallocation.h"
#include "../turn.h"


#include <deque>


namespace scy {
namespace turn {


class TURN_API UDPClient : public Client
{
public:
    UDPClient(ClientObserver& observer, const Options& options = Options());
    virtual ~UDPClient();
};
}
} //  namespace scy::turn


#endif // SCY_TURN_Client_H


/// @\}
