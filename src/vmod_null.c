#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

VCL_VOID
vmod_synth(const struct vrt_ctx *ctx, VCL_STRING name, VCL_INT len)
{
	struct vsb *vsb;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	assert(ctx->method == VCL_MET_SYNTH ||
	    ctx->method == VCL_MET_BACKEND_ERROR);

	if (name == NULL || len <= 0) {
		return;
	}

	if (ctx->method == VCL_MET_BACKEND_ERROR) {
		CHECK_OBJ_NOTNULL(ctx->bo, BUSYOBJ_MAGIC);
		vsb = ctx->bo->synth_body;
	} else {
		CHECK_OBJ_NOTNULL(ctx->req, REQ_MAGIC);
		vsb = ctx->req->synth_body;
	}

	CHECK_OBJ_NOTNULL(vsb, VSB_MAGIC);

	VSB_bcat(vsb, name, len);
}
