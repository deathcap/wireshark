/*
 * packet-minecraft.c
 *
 */

#include "config.h"
#include <epan/packet.h>
#include <epan/prefs.h>

#define MC_PORT 25565

static int proto_mc = -1;

static void
dissect_mc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
    col_set_str(pinfo->cinfo, COL_PROTOCOL, "MC");
    col_clear(pinfo->cinfo,COL_INFO);

    (void)tvb;
    (void)tree;
}
   

void
proto_register_mc(void)
{
    proto_mc = proto_register_protocol (
        "Minecraft Protocol", /* name       */
        "Minecraft",      /* short name */
        "mc"       /* abbrev     */
        );
}

void
proto_reg_handoff_mc(void)
{
    static dissector_handle_t mc_handle;

    mc_handle = create_dissector_handle(dissect_mc, proto_mc);
    dissector_add_uint("tcp.port", MC_PORT, mc_handle);
}
