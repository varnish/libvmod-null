#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

VCL_VOID
vmod_synth(const struct vrt_ctx *ctx, VCL_STRING name, VCL_INT len)
{
	assert(ctx->method == VCL_MET_SYNTH ||
	    ctx->method == VCL_MET_BACKEND_ERROR);

	CHECK_OBJ_NOTNULL((struct vsb*)ctx->specific, VSB_MAGIC);

	VSB_bcat((struct vsb*)ctx->specific, name, len);
}
