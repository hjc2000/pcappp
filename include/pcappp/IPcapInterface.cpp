#include "IPcapInterface.h"

base::Json pcappp::IPcapInterface::ToJson()
{
    base::Json ret{
        {"Name", Name()},
        {"Description", Description()},
    };

    return ret;
}
