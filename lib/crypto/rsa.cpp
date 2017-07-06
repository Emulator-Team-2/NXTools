#include "rsa.h"
#include "polarssl/rsa.h"

using namespace crypto::rsa;
using namespace crypto::sha;

int GetWrappedHashType(HashType type)
{
	switch (type)
	{
	case HASH_SHA1:
		return SIG_RSA_SHA1;
		break;
	case HASH_SHA256:
		return SIG_RSA_SHA256;
		break;
	default:
		return SIG_RSA_RAW;
		break;
	}
	return 0;
}

uint32_t GetWrappedHashSize(HashType type)
{
	uint32_t size = 0;

	switch (type)
	{
	case HASH_SHA1:
		size = kSha1HashLen;
		break;
	case HASH_SHA256:
		size = kSha256HashLen;
		break;
	default:
		break;
	}
	return size;
}

int crypto::rsa::RsaSign(const sRsa1024Key & key, HashType hash_type, const uint8_t * hash, uint8_t signature[kRsa1024Size])
{
	int ret;
	rsa_context ctx;
	rsa_init(&ctx, RSA_PKCS_V15, 0);

	ctx.len = kRsa1024Size;
	mpi_read_binary(&ctx.D, key.priv_exponent, ctx.len);
	mpi_read_binary(&ctx.N, key.modulus, ctx.len);

	ret = rsa_rsassa_pkcs1_v15_sign(&ctx, RSA_PRIVATE, GetWrappedHashType(hash_type), GetWrappedHashSize(hash_type), hash, signature);

	rsa_free(&ctx);

	return ret;
}

int crypto::rsa::RsaVerify(const sRsa1024Key & key, HashType hash_type, const uint8_t * hash, const uint8_t signature[kRsa1024Size])
{
	static const uint8_t public_exponent[3] = { 0x01, 0x00, 0x01 };

	int ret;
	rsa_context ctx;
	rsa_init(&ctx, RSA_PKCS_V15, 0);

	ctx.len = kRsa1024Size;
	mpi_read_binary(&ctx.E, public_exponent, sizeof(public_exponent));
	mpi_read_binary(&ctx.N, key.modulus, ctx.len);

	ret = rsa_rsassa_pkcs1_v15_verify(&ctx, RSA_PUBLIC, GetWrappedHashType(hash_type), GetWrappedHashSize(hash_type), hash, signature);

	rsa_free(&ctx);

	return ret;
}

int crypto::rsa::RsaSign(const sRsa2048Key & key, HashType hash_type, const uint8_t * hash, uint8_t signature[kRsa2048Size])
{
	int ret;
	rsa_context ctx;
	rsa_init(&ctx, RSA_PKCS_V15, 0);

	ctx.len = kRsa2048Size;
	mpi_read_binary(&ctx.D, key.priv_exponent, ctx.len);
	mpi_read_binary(&ctx.N, key.modulus, ctx.len);

	ret = rsa_rsassa_pkcs1_v15_sign(&ctx, RSA_PRIVATE, GetWrappedHashType(hash_type), GetWrappedHashSize(hash_type), hash, signature);

	rsa_free(&ctx);

	return ret;
}

int crypto::rsa::RsaVerify(const sRsa2048Key & key, HashType hash_type, const uint8_t * hash, const uint8_t signature[kRsa2048Size])
{
	static const uint8_t public_exponent[3] = { 0x01, 0x00, 0x01 };

	int ret;
	rsa_context ctx;
	rsa_init(&ctx, RSA_PKCS_V15, 0);

	ctx.len = kRsa2048Size;
	mpi_read_binary(&ctx.E, public_exponent, sizeof(public_exponent));
	mpi_read_binary(&ctx.N, key.modulus, ctx.len);

	ret = rsa_rsassa_pkcs1_v15_verify(&ctx, RSA_PUBLIC, GetWrappedHashType(hash_type), GetWrappedHashSize(hash_type), hash, signature);

	rsa_free(&ctx);

	return ret;
}

int crypto::rsa::RsaSign(const sRsa4096Key & key, HashType hash_type, const uint8_t * hash, uint8_t signature[kRsa4096Size])
{
	int ret;
	rsa_context ctx;
	rsa_init(&ctx, RSA_PKCS_V15, 0);

	ctx.len = kRsa4096Size;
	mpi_read_binary(&ctx.D, key.priv_exponent, ctx.len);
	mpi_read_binary(&ctx.N, key.modulus, ctx.len);

	ret = rsa_rsassa_pkcs1_v15_sign(&ctx, RSA_PRIVATE, GetWrappedHashType(hash_type), GetWrappedHashSize(hash_type), hash, signature);

	rsa_free(&ctx);

	return ret;
}

int crypto::rsa::RsaVerify(const sRsa4096Key & key, HashType hash_type, const uint8_t * hash, const uint8_t signature[kRsa4096Size])
{
	static const uint8_t public_exponent[3] = { 0x01, 0x00, 0x01 };

	int ret;
	rsa_context ctx;
	rsa_init(&ctx, RSA_PKCS_V15, 0);

	ctx.len = kRsa4096Size;
	mpi_read_binary(&ctx.E, public_exponent, sizeof(public_exponent));
	mpi_read_binary(&ctx.N, key.modulus, ctx.len);

	ret = rsa_rsassa_pkcs1_v15_verify(&ctx, RSA_PUBLIC, GetWrappedHashType(hash_type), GetWrappedHashSize(hash_type), hash, signature);

	rsa_free(&ctx);

	return ret;
}