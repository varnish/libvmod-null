#include <stdlib.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"

#include "vcc_if.h"

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	return (0);
}

void
bin_synth(const struct sess *sp, unsigned flags, const char *str, int len)
{
        struct vsb *vsb;

        (void)flags;
        CHECK_OBJ_NOTNULL(sp, SESS_MAGIC);
        CHECK_OBJ_NOTNULL(sp->obj, OBJECT_MAGIC);
        vsb = SMS_Makesynth(sp->obj);
        AN(vsb);
        VSB_bcat(vsb, str,len);
        SMS_Finish(sp->obj);   
        http_Unset(sp->obj->http, H_Content_Length);
        http_PrintfHeader(sp->wrk, sp->fd, sp->obj->http,
            "Content-Length: %d", sp->obj->len);
}

void
vmod_synth(struct sess *sp, const char *name, const int len)
{
	bin_synth(sp,0,name,len);
}
