#include "IPcapInterface.h"

base::Json pcappp::IPcapInterface::ToJson() const
{
    base::Json ret{
        {"Name", Name()},
        {"Description", Description()},
    };

    return ret;
}
