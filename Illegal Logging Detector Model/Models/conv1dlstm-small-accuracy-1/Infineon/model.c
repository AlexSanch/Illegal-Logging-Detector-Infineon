/*
* ImagiNet Compiler 5.3.2704+410e4fb4b60c8e7a62c8d76d1afc33d002b21553
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 05/08/2025 01:05:35 UTC. Any changes will be lost.
* 
* Model ID  23fd7a9c-8d55-435e-96f5-35a4f121fd03
* 
* Memory    Size                      Efficiency
* Buffers   48000 bytes (RAM)         100 %
* State     159120 bytes (RAM)        100 %
* Readonly  35916 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[4].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *data_out);
* 
*  @description: Try write data to model.
*  @param data_in Input features. Input float[1].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_enqueue(const float *data_in);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Initializes buffers to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "mtb_ml_model.h"

#include "model.h"

#ifdef __GNUC__
#define ALIGNED(x) __attribute__((aligned(x)))
#else
#define ALIGNED(x) __declspec(align(x))
#endif
// Working memory
static ALIGNED(16) int8_t _buffer[48000];
static ALIGNED(16) int8_t _state[159120];

// Parameters
static const uint32_t _K7[] = {
    0x0000001c, 0x334c4654, 0x00200014, 0x0018001c, 0x00100014, 0x0000000c, 0x00040008, 0x00000014, 
    0x0000001c, 0x000000a0, 0x000000f8, 0x0000696c, 0x0000697c, 0x00008344, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000004c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff88, 
    0x00000029, 0x00000004, 0x0000001b, 0x766e6f63, 0x736c6431, 0x732d6d74, 0x6c6c616d, 0x6363612d, 
    0x63617275, 0x00312d79, 0x00000001, 0x00000004, 0xffff967a, 0x00000004, 0x00000007, 0x75706e69, 
    0x00315f74, 0x00000002, 0x00000034, 0x00000004, 0xffffffdc, 0x0000002c, 0x00000004, 0x00000013, 
    0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 0x00415441, 0x000c0008, 0x00040008, 0x00000008, 
    0x0000002b, 0x00000004, 0x00000013, 0x5f6e696d, 0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 
    0x0000002d, 0x00006870, 0x00006868, 0x00006818, 0x000067c8, 0x00006778, 0x00004968, 0x00003d58, 
    0x00003148, 0x00003128, 0x00003108, 0x000030ec, 0x000026dc, 0x0000262c, 0x000025dc, 0x000021cc, 
    0x00001dbc, 0x000019ac, 0x0000159c, 0x0000154c, 0x000014fc, 0x000014ac, 0x0000145c, 0x0000104c, 
    0x00000c3c, 0x0000082c, 0x0000041c, 0x0000018c, 0x00000170, 0x00000154, 0x00000138, 0x00000130, 
    0x00000128, 0x00000120, 0x00000118, 0x00000110, 0x00000108, 0x00000100, 0x000000b0, 0x000000a8, 
    0x000000a0, 0x00000098, 0x00000090, 0x00000088, 0x00000068, 0x00000004, 0xffff97a2, 0x00000004, 
    0x00000054, 0x0000000c, 0x000e0008, 0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 
    0x00040008, 0x00000006, 0x00000004, 0x00000000, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 
    0x00000002, 0x00000002, 0x00000004, 0x00000006, 0x35312e32, 0x0000302e, 0xffff9802, 0x00000004, 
    0x00000010, 0x33312e31, 0x0000312e, 0x00000000, 0x00000000, 0xffff7f14, 0xffff7f18, 0xffff7f1c, 
    0xffff7f20, 0xffff7f24, 0xffff9832, 0x00000004, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff7f74, 0xffff7f78, 0xffff7f7c, 
    0xffff7f80, 0xffff7f84, 0xffff7f88, 0xffff7f8c, 0xffff989a, 0x00000004, 0x0000000c, 0x00000001, 
    0x00000001, 0x00000001, 0xffff98b2, 0x00000004, 0x0000000c, 0x00000000, 0x00000000, 0x00000000, 
    0xffff98ca, 0x00000004, 0x0000000c, 0x00000000, 0xffffffff, 0x00000000, 0xffff98e2, 0x00000004, 
    0x00000280, 0xbcacf70f, 0x3e7a01c0, 0x3e2a6e29, 0xbe67794f, 0x3eae7f6c, 0x3e977ebb, 0x3e19c24c, 
    0x3eb4403f, 0xbe99a300, 0xbec84a4f, 0xbd8a3e05, 0xbe633585, 0x3d7f5da6, 0xbed069c0, 0x3d80c91c, 
    0xbf07ed78, 0x3e8edfbe, 0xbef9cacd, 0xbe845685, 0xbeb90a8a, 0x3e18be56, 0x3d32ce5f, 0xbf080378, 
    0xbc2c7f6e, 0x3c53b621, 0x3e73c747, 0xbec33fa8, 0x3ea5a9ff, 0x3d5da4eb, 0xbe8364d8, 0xbebc0736, 
    0x3d384535, 0x3ebf59db, 0xbcedeacf, 0xbd8e209c, 0xbde972b2, 0xbebf5769, 0x3e0755d0, 0x3eaf6a4e, 
    0xbd313fac, 0x3e0c7a93, 0x3eaf91c6, 0x3e9e6322, 0x3c0346a6, 0x3e90fb36, 0x3ebafaae, 0xbf0109d6, 
    0x3e94b023, 0x3e8deada, 0x3dca9ffd, 0x3dc4c4ed, 0xbf09bbad, 0xbf0cefc5, 0x3ece4cea, 0x3ece709e, 
    0xbdc026fd, 0x3e752e4d, 0xbf157c80, 0x3e93b9ff, 0xbee650d8, 0x3eae3ff3, 0x3e3a238a, 0xbe4176b0, 
    0xbe98ae07, 0x3bcd1c17, 0xbdb2a558, 0xbe21755e, 0xbf28e8ef, 0x3e9525de, 0x3d059792, 0xbed21221, 
    0xbeeab9fa, 0xbebb5e0b, 0x3bf01c85, 0x3eacceb9, 0xbe420642, 0x3eb70bfb, 0xbf07f6f3, 0xbdeb2137, 
    0x3ec9670b, 0xbe72fb85, 0xbe3e0a42, 0xbf0487a8, 0xbb3290f3, 0xbf0fd052, 0xbedb2b12, 0x3ea95b3f, 
    0xbf0883bd, 0x3f037749, 0x3e41f706, 0xbe871d5f, 0x3e804482, 0x3eddeb91, 0xbef43a9d, 0xbea7da3e, 
    0xbe95909d, 0xbf08148d, 0x3e64f459, 0xbe396ddc, 0xbe64c6e3, 0xbd7d307c, 0xbf056968, 0x3a8c803e, 
    0xbe1ae1b0, 0x3e83d2f6, 0x3cbc899e, 0x3ee0a514, 0x3eba4cfa, 0x3e839371, 0x3e8e8c18, 0x3e125550, 
    0x3e12451e, 0xbe247de5, 0xbe9dd4b2, 0xbe71433f, 0xbe7c4289, 0x3ecc2014, 0x3e2aa5ab, 0x3ebd0bad, 
    0x3f054739, 0xbebabc75, 0xbef1c1ea, 0x3e10b6d8, 0x3eb31edb, 0xbe71a0ae, 0xbd9ceda2, 0xbef28e18, 
    0xbdefb109, 0xbed3421d, 0x3ef9ad1a, 0x3eb5e160, 0xbe493d4f, 0x3cb40fbc, 0x3e9168ca, 0xbe5668a2, 
    0x3e521c00, 0xbcc2d000, 0x3e899fa2, 0x3e8af056, 0x3e97fc66, 0x3ed87a33, 0xbe6916d6, 0x3edab85b, 
    0x3e4417dd, 0x3eb790be, 0x3ebbcfb2, 0xbe1c19cf, 0xbeb381cf, 0xbecda8ec, 0xbec46bc6, 0x3e82d36f, 
    0x3e115730, 0xbe529754, 0x3d8cc4bf, 0xbe7e9bea, 0x3ed04a5f, 0xbce835e3, 0x3ee20ee1, 0xbea27e3c, 
    0xbe57a5dc, 0xffff9b6e, 0x00000004, 0x00000400, 0x3e40507e, 0x3e3f90b5, 0xbe6525be, 0x3dd73c4d, 
    0x3d07691e, 0x3dca97ce, 0x3d54bf1e, 0xbea7b778, 0xbe8c6e65, 0x3e177ca0, 0x3d2dee91, 0x3ea1c4c6, 
    0xbdc20d6b, 0x3e7cc0ca, 0xbd866186, 0xbe143dde, 0x3ed78fe2, 0xbcc30cd8, 0x3e21a6b5, 0x3dc81a94, 
    0xbebf194e, 0x3e0e187f, 0xbc83ad07, 0x3bebf8c1, 0x3e2bb6f7, 0xbf03c201, 0x3db9c544, 0xbe85fb0b, 
    0x3dfa2906, 0xbee9851d, 0x3d4afd1c, 0xbe1d6f25, 0xbde299d7, 0x3e9b9980, 0x3bd6a96c, 0x3eab95fa, 
    0xbdb3bd2f, 0x3eab520e, 0x3e6de2f1, 0x3eaa5b4d, 0x3e82ed0a, 0xbd5e3c80, 0xbdec788a, 0x3e553305, 
    0x3e58d598, 0xbca33801, 0x3e417fa6, 0x3ebd4287, 0x3de10d96, 0x3ebf9571, 0xbcf404bf, 0xbc0ff067, 
    0x3d9675eb, 0xbe4811c5, 0xbd81df24, 0x3dd2df47, 0x3e07469c, 0x3d1dbd6e, 0xbdcdb3e3, 0x3d6da799, 
    0x3e17b482, 0x3e8b5567, 0xbdb78750, 0xbcc22ba9, 0xbdc7a2e3, 0x3d19d5d4, 0xbd9aa684, 0x3e3a6f14, 
    0x3dbfc46a, 0xbec8bb80, 0x3e6d8fd2, 0x3d73db2a, 0x3d76825f, 0x3de88039, 0x3e8309ba, 0xbd1cc442, 
    0x3ed14bcd, 0xbe62500f, 0xbe420f41, 0xbe34c748, 0xbe1a3cbd, 0xbd60d66b, 0x3ea5a42b, 0xbe811667, 
    0xbe4561f3, 0x3c899caf, 0xbe3740f4, 0xbe5e1a26, 0xbb12dade, 0x3dfd91fb, 0xbd812404, 0x3d805e2f, 
    0x3e92e5bb, 0xbe0ef0d4, 0xbe88c520, 0xbe8d05fd, 0x3e602a9e, 0x3ebd7a97, 0x3e1f5978, 0x3e4f2730, 
    0xbdd318bb, 0x3e816a83, 0xbe592a41, 0xbe1cb209, 0xbe41a8f5, 0x3e1e5d4c, 0x3ceaf28b, 0x3df820c3, 
    0xbe127ba7, 0xbe829d0f, 0xbe6e5da6, 0x3d817c8a, 0x3ea4c09e, 0x3e575253, 0x3eac3193, 0x3e9bf34f, 
    0xbe55650f, 0xbc14a177, 0xbd29b18a, 0x3e09f86f, 0xbd6dcc98, 0x3e94d034, 0x3ea200be, 0x3e49ad2c, 
    0x3e2fbf7f, 0xbd4e53f9, 0x3afadb4a, 0xbd81a8e8, 0x3e239664, 0xbd81fd71, 0x3e849ec1, 0xbe8a4ef6, 
    0xbd5c51b2, 0x3e8afdc6, 0xbd8637c3, 0xbe8ffa6e, 0xbda451a9, 0xbd564ca8, 0x3dd745f6, 0x3dce3335, 
    0xbddf5410, 0xbe80d4d7, 0xbc671204, 0x3e2a9920, 0x3ccb35e3, 0xbeab6f9a, 0x3de677f0, 0x3de37eb5, 
    0x3c9fc123, 0xbe2f1069, 0xbe7fd615, 0xbed3fea8, 0xbed8e860, 0xbdb977f9, 0xbe6ef903, 0x3e122fcf, 
    0xbb1bc9fe, 0x3de66bcf, 0xbeab1a15, 0xbe93b837, 0x3e363a6d, 0xbe7bfb93, 0x3ede55b3, 0x3af53331, 
    0x3ed221c1, 0x3da4e006, 0x3e707730, 0x3e2de342, 0xbe9a800e, 0xbe882bc1, 0x3d329154, 0x3e5a5ef6, 
    0x3e9a981c, 0x3e7587ae, 0x3ea61a4b, 0x3e81a57c, 0x3d76f0cd, 0x3e974da4, 0x3e0207b2, 0x3e3a0166, 
    0x3d7fdce5, 0x3dec0ff2, 0xbe4aff5f, 0x3c03b2cc, 0x3e115d84, 0x3ee9cd17, 0x3c89a70e, 0x3e4261ac, 
    0xbd830c65, 0xbe1101e4, 0x3ccc56e3, 0x3e5741bb, 0x3e199066, 0xbd3a045a, 0xbd98b860, 0xbd040014, 
    0x3e1617ee, 0x3e942089, 0xbe5f9b4e, 0xbe7fad9f, 0xbe8e293b, 0xbda914a9, 0xbe25a9a2, 0xbcafec61, 
    0xbe4c86b1, 0x3e8dacc7, 0xbe06ab18, 0xbe0dc69f, 0x3e91fa29, 0xbe335620, 0x3dc12565, 0xbdc305f3, 
    0x3e91855e, 0xbe822f42, 0xbe955625, 0x3cecf79b, 0x3d964842, 0x3e024f3c, 0xbdecc3d4, 0xbe8236a9, 
    0xbe200173, 0x3e9be12c, 0x3e2d8e37, 0xbdab8bc4, 0x3dacfdd7, 0x3d18e7f0, 0x3e8bbf93, 0xbd287381, 
    0x3de31b06, 0xbe99537d, 0xbdd815d9, 0xbde1defb, 0xbe84f912, 0x3e0c0f42, 0x3dd7065e, 0x3ec7592e, 
    0x3e1bfe61, 0xbdac281e, 0x3de10cb1, 0x3d8b67d7, 0x3be6eb70, 0x3b78df20, 0x3e9c8a78, 0x3e2f0489, 
    0xbe96bf5f, 0x3e33aaec, 0xbd8da4f1, 0x3db8b79d, 0x3e9976f2, 0x3da934a3, 0xbde1e2b6, 0x3dbda176, 
    0x3e748130, 0xbe20d1d6, 0xbda96f0f, 0x3eaf5bed, 0xffff9f7a, 0x00000004, 0x00000400, 0x3eaa6091, 
    0x3e9cefe2, 0x3e7dfd74, 0xbe318098, 0x3e6e98d4, 0x37919778, 0x3e4c83d5, 0xbe56961b, 0xbe2eedbb, 
    0x3dfda322, 0x3e6e6e2b, 0xbe98f46f, 0x3e720b9c, 0x3dd7a623, 0x3e7389e4, 0x3e9e93c8, 0xbb9ec9f0, 
    0x3e85ef02, 0x3d0865f9, 0x3e3137a8, 0xbd3cd0fc, 0x3e30e2a6, 0x3dad257b, 0xbbb5bae4, 0x3d742676, 
    0xbd1b5dcb, 0xbdad465a, 0xbbfe32d2, 0x3e3e6d2d, 0xbca3d65d, 0xbd7d6f1e, 0x3e18f95b, 0x3e3a2065, 
    0xbe582d6f, 0xbea5b39d, 0x3d75733b, 0x3d1fc961, 0xbe3aa910, 0x3e0db44f, 0x3cccbb4a, 0xbe034327, 
    0x3eb1b79a, 0xbd5d67ee, 0x3e549b97, 0xbce3d062, 0x3db5ca90, 0x3e327459, 0xbe2b34eb, 0x3da5753a, 
    0xbdcefcbe, 0xbcee0839, 0xbe946513, 0xbb058e33, 0x3e9ec533, 0xbe8bc0cd, 0x3e2119e9, 0x3e98e6d5, 
    0xbe9f7f66, 0xbe1097f7, 0xbede01b9, 0xbbd47c57, 0x3e1f968e, 0xbde4414c, 0xbe7aac75, 0xbc830a2a, 
    0xbe8106ac, 0x3e359d91, 0x3dc7030e, 0x3dc1070b, 0x3e97e026, 0xbe96c354, 0x3e16dabe, 0xbd63fd43, 
    0x3bfa6333, 0xbe99e659, 0x3dca7613, 0xbe0e340c, 0x3e5f5f5d, 0xbd8c1d17, 0xbe854db1, 0x3ddea2ae, 
    0xbdc54e25, 0xbea26eaf, 0x3e772cab, 0x3ddc5acb, 0xbe312081, 0x3e55f4dc, 0xbd237331, 0xbe94e286, 
    0x3c2ca0e4, 0x3e17cd06, 0xbe094c23, 0x3dfca69a, 0xbe3513e9, 0x3e816630, 0x3da466bc, 0x3dafe8bf, 
    0xbe62c0c5, 0xbe86491c, 0xbe9a7595, 0x3deb08c5, 0x3e65112d, 0xbe36dbd2, 0x3e1dfcae, 0x3e601f92, 
    0xbea310c3, 0x3d633730, 0xbe268028, 0xbe815093, 0x3dee4e6d, 0xbdf18ab5, 0x3da9a6bf, 0x3f09f56a, 
    0xbc69a721, 0xbe2b6633, 0x3efa549f, 0x3eaa34cd, 0x3eaa008b, 0x3e926c05, 0x3c75bc88, 0x3e43c324, 
    0x3e339d95, 0x3e399eb8, 0xbe4905b6, 0x3e6e827f, 0xbdde599d, 0x3e7721f7, 0x3ec408c4, 0xbe14e2f7, 
    0x3d5fae61, 0x3e8da194, 0xbda43c8f, 0x3d33e581, 0xbd35cd93, 0xbccabbfe, 0xbdf4212c, 0xbe566c9d, 
    0xbe11ffd7, 0xbde185f9, 0x3e77d836, 0xbe145cd9, 0xbdc70e75, 0xbe6a4794, 0xbdf62fb7, 0xbea7b2d9, 
    0xbe257aaf, 0xbe092fb4, 0xbe861d39, 0xbdd3d82c, 0xbe88d0a4, 0xbe7d1fad, 0xbe8058d2, 0xbb87e7dc, 
    0xbd0692bd, 0xbe4757f6, 0xbea1dd34, 0x3db72d74, 0xbe49f5ff, 0x3c595e8e, 0xbdff2679, 0xbd1aed1c, 
    0x3eaf0290, 0x3eb8e097, 0xbdbf5d65, 0x3e3eb271, 0x3ca3261a, 0xbe9f4271, 0x3dc6d716, 0x3e99f5e6, 
    0xbe26dff0, 0xbe846e4d, 0xbd7948fa, 0xbdbe2b83, 0x3ea764a4, 0xbcf420eb, 0xbddbb28f, 0x3c45c27e, 
    0x3ea95f34, 0x3de8386f, 0x3e5badad, 0xbea85ccf, 0xbc39bd8d, 0x3b9acb2c, 0xbe8cd166, 0xbe5a0980, 
    0x3c4952c6, 0xbdc59f24, 0x3e9d4109, 0x3e2afe40, 0xbdcc300d, 0x3eb69b4a, 0x3e61ee50, 0xbeea1cb7, 
    0xbdd37da7, 0xbe80f829, 0xbe9a7002, 0xbec2a877, 0x3e8b3745, 0x3d296a4e, 0x3da43f12, 0xbe66d157, 
    0xbe340df3, 0xbdccb16e, 0xbe7ca69c, 0xbe28702b, 0xbe721c3e, 0xbeb3a954, 0xbdb07e80, 0x3c8ba4fc, 
    0xbda45d54, 0x3df71af8, 0xbccbb16e, 0x3d97de2c, 0xbe41b60f, 0xbc921912, 0xbe7cbbdc, 0xbd9dfbe3, 
    0x3e229cc6, 0x3e6e8360, 0xbdba0fc5, 0xbe0277eb, 0x3b760297, 0xbd9ae615, 0x3e394544, 0x3c093bf7, 
    0x3ec00a2f, 0x3c732f06, 0xbe6b4024, 0x3c510210, 0x3e5849d8, 0xbd7f990a, 0x3dba8f35, 0xbc9e7086, 
    0x3e514022, 0xbdacee22, 0xbe399812, 0xbd5f19ae, 0x3dd77255, 0xbdcf9b19, 0xbdc415dd, 0xbe9a54f8, 
    0xbe195dd9, 0xbe6c28ee, 0xbe15ee04, 0x3e6e3736, 0x3e51ec06, 0x3ea2da7f, 0xbcda4724, 0xbeca03b1, 
    0xbd167ddb, 0x3d168fdf, 0x3e5e4c2b, 0x3cdc95c7, 0xbe8670a2, 0x3d2e7fe4, 0xbe24c55d, 0xffffa386, 
    0x00000004, 0x00000400, 0x3de44cf1, 0xbd42c0fa, 0x3ec4914c, 0x3e1b17fa, 0x3eda3ec9, 0xbd660684, 
    0x3e61c6bb, 0x3ebce0fa, 0x3eb7ade3, 0xbe75b0d2, 0x3e720a8a, 0xbe889ffa, 0xbda7ef67, 0x3e471347, 
    0x3e88c5c2, 0x3d306ac0, 0x3daf2670, 0x3eb40c9b, 0x3de36a0d, 0x3e9c08c8, 0x3daf7ac6, 0x3dfdf5b6, 
    0xbe1281c0, 0x3e24ea59, 0xbdc806cb, 0x3dcbef23, 0x3e08809d, 0x3e996239, 0x3e347ad3, 0x3de59906, 
    0x3ebcdd70, 0xbdc97956, 0x3ddc26e3, 0x3ef25ae5, 0x3f039615, 0x3e91d65d, 0x3a200ec4, 0xbc8bc17c, 
    0x3ef3611e, 0xbd3bd366, 0x3ddb4f9c, 0x3f0c74ba, 0x3eae11e4, 0xbdc21b49, 0x3ec1a5b8, 0x3df40e5c, 
    0x3d99758a, 0x3cdfebb2, 0x3e021734, 0x3ebe4b7b, 0x3e4c65f3, 0x3ede140b, 0x3ec89f97, 0x3ecbbb3e, 
    0x3ebd613e, 0x3ca40320, 0x3e0005fc, 0x3f0a7acc, 0x3d53fc25, 0x3cc0bd6d, 0x3ec1d9d5, 0x3eaa2317, 
    0x3e6e74ce, 0x3d3a7e56, 0x3d9532de, 0x3d9723f9, 0x3dfe0f63, 0x3e7b09b2, 0xbddfb7e4, 0xbe6329d1, 
    0x3e863cda, 0xbea57f62, 0x3de7a3c3, 0xbe21676a, 0xbe1f5f94, 0xbe2f3917, 0x3e37f46a, 0xbde03d2e, 
    0x3c9b5e59, 0x3cc7a530, 0x3e95d512, 0xbdcb5635, 0x3dc4e893, 0x3d148c37, 0x3e2f4978, 0x3ce9bd9d, 
    0x3ee9f448, 0x3edd7fe8, 0x3e7c44c7, 0x3e6a2810, 0x3e05f21c, 0x3eef8bf7, 0x3e83b2fb, 0xbddc8802, 
    0x3db1b736, 0x3d296737, 0x3e72a165, 0x3e543310, 0xbc1e40b1, 0x3d70ff3e, 0x3eaf53d3, 0x3eb6b69c, 
    0xbe1d38b6, 0x3e927544, 0x3e317d75, 0x3e27f206, 0x3e9876ab, 0x3eb7fa4c, 0x3d1ea4cd, 0x3ec0a7ee, 
    0xbdb8d0cc, 0x3e912015, 0x3ebde8b7, 0x3eb2a6aa, 0x3f1d68ea, 0x3e739fbe, 0x3eeb2600, 0x3e1f6377, 
    0x3d2fff12, 0x3da5d55b, 0x3e9e81ee, 0x3eb9b17a, 0x3e76229f, 0xbdd6914d, 0x3eb3aad1, 0x3dc70d36, 
    0x3d8ef876, 0x3e585e50, 0xbe081085, 0xbcd46007, 0x3e174b97, 0xbd227b24, 0x3c35a6c1, 0x3ddb3cdd, 
    0xbe886111, 0xbd38efe9, 0x3e28b892, 0xbe993491, 0xbdeb9908, 0xbdf94257, 0xbe5c1202, 0xbdd08b2f, 
    0x3e20dfcd, 0xbe3ec0b6, 0x3e5238e3, 0xbe3ed9c0, 0xbe0879c8, 0x3ea27582, 0x3de3377c, 0x3d9c97f0, 
    0xbdda4fd1, 0xbd8b8a14, 0xbe06885b, 0xbe22cfeb, 0x3dd97128, 0x3eb8c487, 0xbe5608c5, 0xbe330871, 
    0xbe6d84d2, 0x3e43fe19, 0x3e5a7d0c, 0x3eafa93c, 0x3efc6b01, 0x3ec4648d, 0xbd878b85, 0x3e6ec40a, 
    0x3e6255ee, 0x3eb61726, 0x3e0a8e6c, 0x3ef24cf1, 0x3e0a47b5, 0x3deadf20, 0x3de38431, 0xbe038cd8, 
    0x3d9cb01e, 0x3d8188d8, 0x3c871f6a, 0xbd643d67, 0x3e84c69f, 0x3db28a87, 0xbec9e212, 0x3db8b54d, 
    0xbd7c5f97, 0xbd960cf4, 0xbd4ad36c, 0x3ec9da43, 0x3f0142c3, 0x3e0cd281, 0x3e17bd32, 0xbd8a2774, 
    0x3ec7a355, 0x3eebc727, 0xbd633d10, 0x3e7dd95d, 0x3d2aa4c9, 0xbd1061af, 0x3d1be1d9, 0x3e25795c, 
    0xbed5ba43, 0x3e4d93ec, 0xbd3462a1, 0x3e6b31f2, 0x3d1abac7, 0xbe228ca5, 0xbecace95, 0x3e8dae0f, 
    0xbe87b771, 0xbea08ed2, 0xbe05e1d0, 0xbe6f8006, 0x3d849e6b, 0xbe8332dc, 0xbe2d447d, 0x3e49961b, 
    0xbe4ec785, 0x3d637808, 0x3da91554, 0xbe6f3f15, 0xbe4f6184, 0xbdd3bd3c, 0xbce8f52f, 0x3ea9aace, 
    0x3e3802fe, 0x3e426c07, 0x3ecf76ff, 0x3e8ae1a2, 0x3e7ba173, 0x3e44cb20, 0xbb88f21a, 0x3e31536b, 
    0x3edfdb23, 0x3ededf54, 0x3e3de418, 0x3e9ccedf, 0xbd2c1429, 0x3dfc6ab5, 0x3ed1f774, 0x3ea268dd, 
    0xbd837b33, 0x3dc6f65c, 0x3e52e3ed, 0x3e14caf1, 0x3dbe840c, 0xbe49a464, 0x3e12dba0, 0x3e2e0a2e, 
    0x3e7d44e7, 0x3e5070d0, 0x3e4b892d, 0x3e5477b4, 0x3d97e620, 0x3e654a78, 0x3e846dbb, 0xbe7d3c6d, 
    0xbcc832a9, 0x3d139156, 0xffffa792, 0x00000004, 0x00000400, 0xbdcd3d7c, 0x3ec4dbf7, 0xbd8e5ce6, 
    0xbe04c15c, 0x3ec4dc70, 0x3e81200e, 0xbd2df2ee, 0xbceef603, 0x3dd5fd6f, 0xbe595ea5, 0xbe4a7963, 
    0x3e2fc12c, 0xbc5bd5b0, 0x3d6b28dd, 0x3e3b439b, 0x3dbf1732, 0xbc45a387, 0xbbb90126, 0x3e083aab, 
    0xbe299c74, 0x3d46244e, 0xbdf334ee, 0xbe210d3b, 0xbeae2dbe, 0xbd573694, 0xbe16d279, 0xbdb8d945, 
    0xbd263d8a, 0x3d8ddedc, 0xbdeb85cf, 0x3ca097e0, 0xbe0d9aee, 0xbeb2ed20, 0x3e60fe02, 0x3df7aa7d, 
    0xbee5f941, 0xbc2663f5, 0xbe0cf57f, 0xbf0f46fb, 0xbe555e15, 0x3d987dd8, 0xbe69cc9e, 0xbd2d73bc, 
    0xbf08c947, 0xbe06d8c0, 0xbe118c35, 0xbed59e7c, 0xbe29ffb1, 0x3e12a9c4, 0xbef15128, 0xbf0043ec, 
    0xbe70323c, 0x3e8bcb56, 0x3f192d8d, 0x3ecb62bc, 0x3d4c90e1, 0x3e71b210, 0xbeb9d2ff, 0x3dd91bad, 
    0xbd9dbea9, 0xbcebb7f8, 0xbcd08e1a, 0xbe589046, 0xbe2f0bfb, 0xbe1d6ce0, 0xbed3ddb2, 0x3d5a0d00, 
    0xbce263d3, 0x3e0f8e25, 0xbcf99962, 0x3d08b73f, 0xbd86cd37, 0xbe2dac92, 0x3e780384, 0xbeb4c86c, 
    0x3ca47924, 0x3e2c1303, 0xbde61e78, 0x3be12bb9, 0xbdb27602, 0x3eb64648, 0x3e288979, 0xbd702698, 
    0x3c838c69, 0xbcf007d9, 0xbba2267d, 0x3da5df77, 0xbcaddf9d, 0x3c1b8e33, 0xbdbfcea2, 0x3e907fd1, 
    0x3e6b5b99, 0x3d9bbc4e, 0xbe2b8f4d, 0x3dd626f9, 0x3e2129a5, 0x3e433885, 0xbc28d2a3, 0xbd770d02, 
    0x3e03a576, 0x3e32d73a, 0x3da9a0fa, 0x3eac07b1, 0x3c8e30e6, 0x3ee36193, 0xbed11aeb, 0x3ef57a11, 
    0xbe119363, 0x3e7988fb, 0x3ea41dc6, 0x3eec9d1d, 0x3eebcf31, 0x3f503512, 0xbe99a8af, 0xbf3a2274, 
    0x3cde4583, 0x3e6a3cd3, 0x3eb83136, 0xbd63be59, 0xbe84d0bd, 0x3e9478d5, 0x3d635ac9, 0x3eb42a38, 
    0xbe7e1ad7, 0x3e54f499, 0x3efd18b5, 0x3e8d3dba, 0x3e07fa8f, 0x3b8f69bd, 0x3e00ef19, 0xbde0531b, 
    0xbe0909d5, 0xbe2bad2c, 0xbd444415, 0xbe255c75, 0x3e451f22, 0x3ec478f2, 0xbca31bfb, 0xbeac67e5, 
    0xbe541ceb, 0xbe73e0e1, 0x3e0bfbf1, 0xbd9cc294, 0xbe3da7a3, 0x3df78c28, 0x3ec13e81, 0x3ebfb288, 
    0x3e68ddb2, 0x3dc84ab6, 0x38b4fe5d, 0x3e41f5f3, 0x3ec41589, 0x3dc20876, 0x3e2cfffa, 0xbd8dce54, 
    0x3e7c3e43, 0xbe477cf8, 0xbdf8ba04, 0xbba9859e, 0x3e91ba1d, 0xbee92fee, 0x3dacd0f6, 0x3ee4e8bc, 
    0xbdbb3881, 0xbd8c3183, 0xbec311ad, 0xbe4c649a, 0xbe37e295, 0x3d4dd067, 0xbeb0075b, 0xbed2c188, 
    0xbf04e870, 0xbd28294f, 0xbdb55108, 0xbe9219cd, 0xbe9eeefa, 0xbe3e007d, 0x3d72b51d, 0x3e4546e3, 
    0x3e2dbe5e, 0xbecd157b, 0xbecc48eb, 0xbe6e38b1, 0xbe4175be, 0x3d11747b, 0xbe6c5c50, 0x3d0ec3aa, 
    0x3cd82991, 0xbe11d9cc, 0xbe08fa12, 0xbe8055b5, 0xbe80b48d, 0x3d632a7c, 0xbba50216, 0xbea65877, 
    0xbe201262, 0x3ca581f7, 0x3df36a7f, 0xbe1972db, 0x3d8ab4f6, 0x3e4b7063, 0xbe9354e5, 0xbd4977a4, 
    0xbefa7dc0, 0xbeb6296c, 0x3e885a5e, 0xbe98a096, 0xbd8c8767, 0x3d0b3a49, 0xbe7947e1, 0xbde8e605, 
    0x3c366613, 0xbe4e320a, 0x3e5a0216, 0xbeac6747, 0x3c3eccf3, 0x3ca4cf92, 0x3e11b1e5, 0xbbe750ab, 
    0xbe60c3ef, 0xbd31a2fb, 0xbe32fb42, 0xbe70ec48, 0xbe647288, 0xbe1ef5c4, 0x3e1cddd5, 0x3d580bd4, 
    0x3df7b50c, 0x3e0440ae, 0xbe905605, 0xbdbe109f, 0xbe7edb81, 0xbeb64229, 0xbd63ab7b, 0xbd527142, 
    0xbdd877d3, 0x3e187e39, 0x3db35ff6, 0xbdc41a69, 0x3e3b81a8, 0x3e16fc58, 0xbd3402b4, 0x3ac6bf26, 
    0xbe74f7d9, 0xbec426a3, 0xbe68ee0e, 0xbf078310, 0x3c20d74e, 0xbdb1b928, 0xbe9d96b6, 0xbddbb3b7, 
    0xbef8ad1d, 0xbecdba31, 0xbc35cfc5, 0xbe241ad3, 0xbeb10842, 0xffffab9e, 0x00000004, 0x00000040, 
    0x3e11564d, 0xbda4d4bc, 0xbd53ec40, 0x3d708ab6, 0xbd907827, 0x3d5494b4, 0x3d1c5347, 0x3e2c9138, 
    0xbd61b8c4, 0x3da16bba, 0x3e8ee3af, 0xbde58b9a, 0x3d8eaf1a, 0xbd8004e1, 0x3d7fc94b, 0x3d72bb7f, 
    0xffffabea, 0x00000004, 0x00000040, 0x3d4a9a71, 0x3d1c4913, 0x3d65b82c, 0xbd57de4c, 0x3d847d89, 
    0xbd94cfbb, 0xbdbd625b, 0xbd3532f3, 0x3e0c43ac, 0xbdf780b5, 0x3d576681, 0x38d37d46, 0xbd74e18f, 
    0x3d03d306, 0x3d27de0a, 0xbc47a84d, 0xffffac36, 0x00000004, 0x00000040, 0x3f8ef924, 0x3f836e73, 
    0x3f96fa50, 0x3faa7353, 0x3f677a0c, 0x3f9f68ef, 0x3fa26034, 0x3faed57a, 0x3f896ee9, 0x3f922a93, 
    0x3fa99ebb, 0x3f7ca506, 0x3f93f518, 0x3f80bff4, 0x3fa2ca7f, 0x3f89839e, 0xffffac82, 0x00000004, 
    0x00000040, 0x3b5dac14, 0xbd6c2f16, 0xbea5e0d3, 0xbe9ef7e7, 0xbdd478c1, 0x3d07cff0, 0xbd490055, 
    0xbeb47a61, 0xbcab3f9c, 0x3e377cf3, 0xbe3ac2a9, 0xbe918088, 0xbd9f5a48, 0xbd3465ba, 0x3db471d9, 
    0xbe384fea, 0xffffacce, 0x00000004, 0x00000400, 0x3e39d426, 0x3ec515a1, 0x3e6655d0, 0x3e4013c8, 
    0x3d23731e, 0xbe81f251, 0xbde6ffad, 0x3e02dcbc, 0xbe968dde, 0xbeaa7f54, 0x3e3451ea, 0xbbbb413b, 
    0xbe338aec, 0x3dcd3f7b, 0xbdaaf841, 0xbd551d6f, 0xbe674a96, 0xbd111a65, 0x3d625c5f, 0x3e357f44, 
    0xbcba431d, 0x3d5832ae, 0xbdb925ef, 0x3d660dd2, 0xbe389e68, 0xbd5fdb6d, 0x3e124683, 0xbe3225d9, 
    0x3cddd902, 0xbe8e233c, 0x3c95edad, 0x3e136aa5, 0xbe0da0bf, 0xbd3a83ed, 0xbe4651e9, 0x3dba5e7a, 
    0xbe94a905, 0xbd9fff46, 0x3cb8517f, 0x3cd2c413, 0xbc7633dc, 0xbd399620, 0xbe4b6c6a, 0x3dec891e, 
    0xbcba6b3a, 0xbc20a2c3, 0xbd8754ca, 0x3d3bd258, 0x3ec62cd3, 0x3e11ce6e, 0xbe4af5ea, 0x3ef0b5cd, 
    0x3da268f8, 0xbe8077b7, 0x3e057bab, 0x3dba8d06, 0xbd154d8d, 0x3d614202, 0x3deca423, 0x3ea921e5, 
    0xbd9066d8, 0xbce11026, 0x3d51320c, 0xbe6935b8, 0xbbdf89c8, 0xbeb825fc, 0xbe9a9016, 0xbdebf2b1, 
    0x3d91e76f, 0xbdf1dcfb, 0xbc1d9916, 0xbe25c281, 0xbe61d778, 0x3d500eef, 0x3c4ec5c3, 0xbe4c493b, 
    0x3deac035, 0x3e292df0, 0xbe942db4, 0x3e92b429, 0x3cc119b9, 0xbe81c8d4, 0x3e164dcd, 0x3e8eb203, 
    0x3ecf174e, 0xbd4e8649, 0xbbd99317, 0xbd7d037b, 0x3dddf1b7, 0xbe080bd4, 0x3dbc7902, 0xbe249539, 
    0xbe3acaee, 0xbd1b62b8, 0xbe38116c, 0x3e15c426, 0xbe572cb4, 0x3cc7d6bf, 0xbe95fe6a, 0xbe834787, 
    0x3de86ae8, 0x3cff9205, 0x3e3d4855, 0xbd9ef3fd, 0x3e3293b3, 0x3d64656d, 0x3e57c70c, 0x3db6bcf5, 
    0xbe3c8c6f, 0xbdfc57f3, 0xbda5ba36, 0x3c93c63b, 0x3df0e55e, 0x3e259248, 0xbeca3a77, 0x3e0e9099, 
    0x3e3db4d6, 0xbdf73870, 0xbd42cab7, 0x3dfdd969, 0xbe25add3, 0x3c5dc710, 0x3e9534dc, 0x3e3441d6, 
    0xbe8b5e01, 0x3d761da1, 0x3f0933a4, 0xbeaa038c, 0xbe1c6076, 0xbdd3bc7f, 0xbd9b7ddb, 0x3dddd55a, 
    0xbdb779ac, 0x3d910b07, 0x3eed0544, 0xbe594a0d, 0x3e03babd, 0x3ccd5e61, 0x3e1161b4, 0xbecea5e0, 
    0x3e9f3de2, 0xbe232d2d, 0xbe0e6725, 0x3e3bdafb, 0xbe882339, 0x3e0c2a95, 0x3e9e1759, 0xbe5dc919, 
    0x3e6d4f87, 0xbdba47a9, 0xbc2185e9, 0xbe1043e5, 0xbdc24417, 0xbd2a8dd8, 0xbda625ca, 0xbe56bf75, 
    0xbd03d9d3, 0xbd316dc7, 0x3c7ac37b, 0xbd466395, 0x3e8b84cc, 0x3d84a8ce, 0xbdf7b537, 0x3e4c1fa9, 
    0x3e170cc1, 0xbe5f0c71, 0x3d893d52, 0x3ec84eb7, 0x3e17ca12, 0xbea77963, 0x3ec58488, 0xbb0a64eb, 
    0xbe0ce998, 0xbe950586, 0x3dba19f9, 0xbdaabf14, 0x3e375dcd, 0xbd93c740, 0x3d57a52d, 0xbb8697c5, 
    0xbd894d24, 0xbd69563c, 0xbccdbadd, 0x3e8a9c36, 0x3e23ab34, 0x3dd9df13, 0x3e8a91e0, 0xbd268de4, 
    0xbee7a9cf, 0x3d239142, 0xbc5e27e9, 0xbe35aa03, 0x3c84eadd, 0xbe014bdc, 0x3d5ffa29, 0x3e8a4020, 
    0x3d0db923, 0x3c74cdda, 0xbd59f63a, 0x3e8f648d, 0xbd93c156, 0xbe73b7b2, 0x3e0bc152, 0xbddbac11, 
    0xbcc981eb, 0x3d9bb746, 0x3d22540b, 0x3d147528, 0xbd660f7d, 0xbe370bbd, 0x3e8289f5, 0xbda6d78c, 
    0x3e278473, 0x3bc687e7, 0x3e9ee4da, 0xbdadb6c4, 0xbc82bb85, 0x3ef90087, 0xbdf6dcbe, 0xbe61ad02, 
    0x3d222422, 0x3dd8eaf9, 0xbeaed667, 0x3e1e6ed3, 0xbe0734de, 0xbe7e411a, 0xba850d62, 0x3ea3b64a, 
    0xbe9d869a, 0x3c5d176e, 0x3e4991af, 0xbdfbb5be, 0x3df50e0a, 0x3df32dd5, 0xbe0fb1b1, 0xbd2d9058, 
    0xbe357b52, 0x3d472448, 0xbe827a39, 0xbda89c8a, 0xbd002411, 0x3d97b4ff, 0x3d9c9082, 0x3e001f4f, 
    0xbe0471db, 0xbe40d144, 0xbe5dd2e2, 0x3d585311, 0xbe7a8c0e, 0x3c814136, 0x3e5b3328, 0x3d871647, 
    0x3ba61f62, 0x3e0d0e82, 0xbd0752f8, 0xbd101b6a, 0xffffb0da, 0x00000004, 0x00000400, 0x3df819be, 
    0x3e0b7cde, 0x3e80e2a3, 0xbd159597, 0x3de1b4c9, 0xbd1c7adb, 0x3d35664c, 0x3ddad482, 0xbcf85de7, 
    0xbe4db934, 0xbd4bbaf2, 0x3d289a04, 0xbeb18e7d, 0xbd38c72b, 0x3e883518, 0xbdcd80b4, 0x3d3bcf5b, 
    0xbe34ecaf, 0x3cd821e4, 0x3cd82278, 0x3e21a94c, 0x3dd6a829, 0x3b71ff16, 0x3eceb027, 0x3b0a7233, 
    0xbc8f65d9, 0x3d9b1da4, 0xbd19bb48, 0xbe58c52d, 0x3e90d729, 0x3d82ecb0, 0x3d64fc63, 0xbcb8bcbf, 
    0x3d8fe388, 0xbe821acf, 0xbdda4143, 0xbd8f5d0b, 0x3a6dbcf7, 0xbe40b1ad, 0x3e4ba108, 0x3d6ed2fe, 
    0xbe4555a6, 0x3d7b14fc, 0xbdb00ce2, 0xbe41dd10, 0x3e764f3c, 0x3e29a957, 0x3c60028c, 0xbde4126f, 
    0x3c90ec03, 0x3c10c1d2, 0x3c2f2155, 0x3e44c24a, 0xbdf5970f, 0x3bc07cb9, 0x3e3b25d2, 0xbd213adf, 
    0x3daa48b7, 0xbd89bf93, 0xbdfc9815, 0xbb1f8829, 0x3d24be10, 0xbbf2a71d, 0xbddd8ebe, 0x3d82b91c, 
    0xbe0fff7f, 0x3e386371, 0xbd02003e, 0xbccf7f0e, 0x3e3713f7, 0xbcfc97ea, 0xbb22eabd, 0xbda7f4d6, 
    0xbe167d3f, 0xbd4b3dd7, 0x3e366f6c, 0xbe55d771, 0x3d938aaf, 0xbd2ce68c, 0xbddb5ace, 0xbe80c893, 
    0xbd2c4088, 0xbc8829a8, 0xbd122381, 0xbc512430, 0x3e34b6a1, 0xbdd22cf2, 0xbe11cf96, 0xbe107200, 
    0x3eb338fc, 0xbcdbdad1, 0x3c2762b1, 0xbd12eec5, 0xbcc20aac, 0xbe7669a0, 0x3d841d62, 0xbd9ff01e, 
    0x3d142bf4, 0x3dbcfa6c, 0x3e7af476, 0xbacd3a9d, 0x3e563f32, 0x3f01fad2, 0xbe53a9e0, 0xbdd9f1ac, 
    0x3e3fba2f, 0xbd4debaa, 0x3d87424f, 0xbe10a63d, 0xbd4ab72e, 0x3dc8fb16, 0x3dc65207, 0xbe3697c0, 
    0xbdca149f, 0xbce1252a, 0x3e45bc67, 0x3ce5513c, 0x3e4c4433, 0x3e3b21ff, 0x3d9272db, 0xbe2d6803, 
    0xbc734aed, 0xbd825428, 0xbd613d51, 0xbc72158a, 0xbdc438cb, 0xbddd07f0, 0x3d61916d, 0xbd490ce8, 
    0xbcf1ec22, 0x3dae07c2, 0x3ca7ee77, 0x3d99cef4, 0xbe981b19, 0x3de6450e, 0xbb9cba7b, 0x3e2d1755, 
    0xbe17987a, 0x3e8176b0, 0x3e0af8a0, 0xbe0ec637, 0x3da789bb, 0x3ea2ca92, 0xbbc1a544, 0xbea04dfd, 
    0xbea0560d, 0xbcf023c0, 0x3de53195, 0xbd9fc177, 0x3d5b3895, 0xbe24cf75, 0xbe329fab, 0xbd04d544, 
    0x3e6e64cd, 0xbe9bd102, 0xbdb684cf, 0x3e956244, 0x3dc94a84, 0x3caa4295, 0xbde21641, 0x3e579547, 
    0xbcd0dae2, 0xbb13f469, 0x3e01d683, 0x3e632d18, 0xbd3c0cc1, 0xbdc4a8c6, 0xbe09ad09, 0x3e21aec1, 
    0xbe136664, 0xbdb9599f, 0x3db2c249, 0x3e251f34, 0xbc41a8dc, 0xbdedacf5, 0x3dfbb57a, 0x3c123f3e, 
    0x3d51e336, 0x3d2b92d9, 0xbe9ffea4, 0x3b941f54, 0x3dff60fa, 0xbd567a46, 0x3e5f9547, 0xbd8b3009, 
    0xbdebcb36, 0x3d16ec0b, 0xbe83d88f, 0xbd8c1b97, 0x3c67f8f7, 0xbe42379b, 0xbd59aab1, 0xbce79c27, 
    0x3cb49a32, 0xbe8c3691, 0xbe478797, 0x3cc01f04, 0x3e280ff7, 0x3e229714, 0xbe676d9c, 0x3d336fb0, 
    0xbddabe03, 0xbe5356d6, 0x3d7bc8e2, 0x3dda8766, 0x3da5c5cf, 0xbe67edf9, 0xbb3ae02e, 0xbe257084, 
    0xbe732141, 0x3d53dc66, 0xbde987ab, 0x3e154058, 0x3cda7e02, 0xbe09b7de, 0xb768a900, 0xbe000d1a, 
    0xbe31bdaa, 0x3e283d30, 0x3dd3fbeb, 0x3e8c3052, 0x3d98b269, 0xbdf0f602, 0x3da1ae58, 0x3e2cb232, 
    0x3e1778bb, 0x3d52eb60, 0x3d9ac244, 0x3df5d179, 0xbe741bf3, 0xbe1bda19, 0x3d8c4805, 0xbdcd93f1, 
    0xbacd0afa, 0x3e99bbd1, 0x3d44dd25, 0xbeb47c37, 0xbe060e8a, 0x3eb88a8c, 0xbc84f3db, 0x3c3eddc7, 
    0xbd9288d6, 0xbd9982a4, 0xbea0f226, 0xbc264d75, 0xbe05d388, 0xbe29d7f7, 0xbef92be4, 0xbd6e121e, 
    0xbe5e11d0, 0xbd98c1db, 0x3e06dc8f, 0xbe631ec9, 0xbd34d7ef, 0x3e4060b2, 0xbe5884f0, 0xffffb4e6, 
    0x00000004, 0x00000400, 0x3dd4b500, 0xbd0b04cf, 0xbe1e1c35, 0x3ccf07fb, 0x3dacd3e5, 0xbe7bffd4, 
    0xbd5a5cab, 0x3e384554, 0xbd87afdd, 0xbdf82107, 0x3e3ec048, 0xbe3b1e13, 0xbe3d4dc1, 0xbe4d2669, 
    0xbc91364d, 0xbec01621, 0x3e105a88, 0xbd5963d6, 0x3df39104, 0x3e30dfd3, 0xbc7c64de, 0xbc7904c3, 
    0xbe048094, 0x3e90ba6e, 0xbea301dc, 0xbcad561d, 0x3da1494c, 0x3d8e3dc9, 0xbe57924d, 0x3dbdea9e, 
    0x3e43c105, 0x3dc4ce63, 0x3e84f156, 0xbda036dc, 0xbe02676d, 0xbd259071, 0x3cc803a4, 0xba5a04f2, 
    0xbe9975cf, 0xbda84699, 0x3df6843b, 0xbe363847, 0x3e40ee0d, 0x3dfa6712, 0xbe66700a, 0xbe8beb5c, 
    0xbd47549a, 0xbeb4443b, 0x3eb63f5e, 0x3e8e5536, 0x3d902dce, 0x3ec6623a, 0x3e1a5270, 0xbe1b8815, 
    0xbea8943e, 0x3f262779, 0x3e4bd7ef, 0xbe97bdaf, 0x3ecf5dc5, 0x3f3d6b1c, 0xbedf0f66, 0xbee157cf, 
    0x3e016b6c, 0xbf156f1e, 0xbe5a8ed5, 0xbdf57072, 0xbec77fee, 0xbc9ea264, 0x3df1894a, 0x3dd1132e, 
    0xbe010597, 0x3d8c199a, 0x3e163849, 0x3e95a59f, 0x3da3ef70, 0x3d198927, 0x3e623f55, 0x3e81e13e, 
    0xbe7e8f02, 0x3d0358cc, 0x3eb9bd08, 0x3da8ddc1, 0x3e1236b2, 0x3dff3b2f, 0x3db00b4b, 0x3e2633fe, 
    0x3dea5c17, 0x3ea27aa7, 0x3dcecf72, 0xbe8cdb2e, 0x3d120ee3, 0x3eb21bf9, 0xbe6e9123, 0x3e870912, 
    0xbe46e555, 0xbe76c700, 0x3eee138c, 0x3ec8c8bd, 0x3cd47a23, 0x3e6648bc, 0x3b795a2c, 0xbebd9aa8, 
    0x3e797890, 0x3e8187d5, 0x3ec2eed1, 0xbdb5f095, 0x3e83f352, 0x3e825cd4, 0xbef699bb, 0xbe83af4d, 
    0x3e9d9ed1, 0xbea01b55, 0x3ec76b4c, 0x3ee36ba2, 0x3dea2002, 0xbdcf0dae, 0x3e203d58, 0xbe13e169, 
    0xbec4fda1, 0x3eb8dbb3, 0x3ed1240b, 0xbe8a39f2, 0x3f04bcf5, 0x3f1faacc, 0xbf13fe6e, 0x3cb9a0da, 
    0x3ea32dd8, 0xbeeef494, 0xbdeb41a3, 0x3e48e3f9, 0x3c293b0a, 0x3e52fe1f, 0xbe2324b4, 0xbeb5d449, 
    0x3dd69e31, 0xbdcee7b3, 0x3e875577, 0xbcd54954, 0x3e892062, 0xbdfa284a, 0xbe38f791, 0xbe707124, 
    0x3ddbccf6, 0x3e27ac91, 0x3d4db6b4, 0x3e9c9be4, 0x3d2d04be, 0xbddc4b3d, 0x3e963840, 0xbeab595e, 
    0xbe608475, 0x3d93337c, 0x3d203214, 0xbe23a47f, 0xbc5c8dbe, 0x3e194323, 0xbd5c8d50, 0x3d3985a4, 
    0xbcc72d74, 0x3c951bc2, 0x3f03c7e7, 0x3e885ac5, 0xbe1050f0, 0xbd6a5dfc, 0xbdbb32c9, 0xbeaa4ebf, 
    0xbd1e52f8, 0x3ebe8afa, 0x3ecb191f, 0xbeca9def, 0x3e8e2d2c, 0x3eb77f97, 0xbed67eac, 0xbebad4df, 
    0x3eb258e2, 0xbe5af846, 0x3e007ca5, 0xbd6c9421, 0x3e0d04fa, 0x3c3ad216, 0x3d3bf026, 0xbdbeac97, 
    0xbe8f0db8, 0x3e6d1810, 0x3d4cfaed, 0x3e1f5012, 0x3b13bfac, 0x3e2dc40b, 0xbe6f4219, 0x3dfac7be, 
    0xbdf86807, 0xbd342ed5, 0x3e8bb0f9, 0x3dbc681f, 0x3e45d1ca, 0x3e383422, 0xbe01f30c, 0xbe188dd6, 
    0x3cc7e18a, 0x3dcfa9f9, 0x3e38527b, 0xbdf84659, 0x3d36b3a1, 0x3d92c182, 0xbe9af463, 0xbe894674, 
    0xbda00411, 0xbe380e4b, 0xbe97964e, 0x3e1ecbb5, 0xbe2439c8, 0x3dc7deda, 0x3ca2c34d, 0xbe3a0a7a, 
    0x3e38c8f0, 0xbdc4b751, 0x3ea3f4aa, 0xbe37d5a3, 0xbd90992a, 0x3cb9bc28, 0xbcb70629, 0x3e254f48, 
    0xbe1b9083, 0x3cab043e, 0x3e2434f7, 0x3e839879, 0x3e4575f4, 0xbc8f442e, 0x3ee1924b, 0x3e5662f0, 
    0xbd06ae07, 0x3e82d47e, 0x3e3bf30b, 0xbe453371, 0x3db2b1de, 0x3e8ed726, 0xbd2c20f5, 0x3e41eabc, 
    0xbdbbc324, 0xbe5e4153, 0x3d53862f, 0x3e80016b, 0xbdf1f10b, 0xbd1e8733, 0x3e1c16ee, 0xbd90add5, 
    0xbda72bcf, 0x3e65ac4e, 0xbe01321b, 0x3e0254d8, 0x3e90fba4, 0x3e849bac, 0xbe7e4a5d, 0xbc3b6665, 
    0x3dffce02, 0xbe70e341, 0xffffb8f2, 0x00000004, 0x00000400, 0x3d08fe0d, 0x3e15b61c, 0xbe0fa579, 
    0x3c36216a, 0x3d31d1f9, 0xbd4375e3, 0xbe294d1e, 0x3e216163, 0x3d417db3, 0xbcad5d6a, 0x3bbae096, 
    0x3bf31589, 0xbda6d474, 0x3daf3971, 0x3d5ccf7a, 0xbe011aa9, 0x3bdb0654, 0xbe0181c5, 0xbb92a841, 
    0x3c6f4e09, 0xbe929fa2, 0x3eb5f74b, 0x3e136739, 0x3e3e4d85, 0xbe861fdc, 0xbbdff1b4, 0xbe482cba, 
    0x3e6d60be, 0xbd73d64c, 0x3d85f2ab, 0x3d831af0, 0x3e8577ec, 0xbea0366b, 0xbe8098ab, 0x3dc97760, 
    0x3de10266, 0x3e491eca, 0x3da05e60, 0x3d88dd19, 0xbf007d69, 0x3d773bcf, 0x3ed947fe, 0xbf10335a, 
    0xbec78208, 0x3eb18995, 0x3e468f5a, 0xbecedfbb, 0x3ea3a680, 0xbe3dc948, 0xbe4cb56b, 0xba875832, 
    0xbe102644, 0xbeb05050, 0x3f2e4127, 0x3c2589c6, 0x3c862601, 0xbe9a0abf, 0x3ef1a43e, 0xbebad440, 
    0xbd0e52e9, 0x3f05661b, 0x3e13c60c, 0xbf09e846, 0x3efccbea, 0xbe8aac03, 0xbe7c6b37, 0xbe8285ec, 
    0x3da5cd5d, 0xbe0056a0, 0x3e718dc7, 0xbd9c8ee3, 0x3d1b62c2, 0xbe9415a3, 0x3e422cd4, 0xbe2da7a7, 
    0xbdcfde94, 0x3ccd5692, 0x3e0f4291, 0xbf1ad16c, 0x3ece2146, 0x3e2545d1, 0x3dc8ca6c, 0xbe10efdb, 
    0x3e41347a, 0x3e0ba9b0, 0xbe091b2a, 0x3e1c8df5, 0xbd854c27, 0x3dd2d129, 0x3a83775a, 0x3e32de96, 
    0xbe09771a, 0x3e11c065, 0xbdaa9643, 0x3d834c08, 0xbd90d6e5, 0xbe1839ac, 0xbced8205, 0x3e753bec, 
    0xbd93e4af, 0xbdb7a536, 0x3dc446ab, 0x3dc4a425, 0xbd5008b8, 0xbda5c390, 0x3dbd6708, 0xbdf2b88b, 
    0xbd2c5925, 0x3da54c6e, 0xbe388457, 0xbdaeee37, 0xbcefe011, 0xbe980678, 0xbf1493f6, 0x3ebabef1, 
    0xbe175275, 0xbe990e8f, 0x3f1c009e, 0xbd17aec6, 0xbe223e2c, 0xbf29157c, 0x3f09ce75, 0xbf6262a3, 
    0xbec508ea, 0x3e6e86b1, 0x3edcf1d5, 0xbf016912, 0x3ed49d49, 0xbc7db514, 0x3d8f63ec, 0xbe709fec, 
    0x3e315afa, 0x3ce6847a, 0x3c9dfe86, 0x3cee7f4c, 0xbe8f15cb, 0x3e793235, 0xbdcbe784, 0x3e1e536b, 
    0xbe9303a7, 0xbd2c1a35, 0xbd316ff0, 0x3dfbb7a3, 0x3c81b1ac, 0x3dbe9048, 0x3cf12358, 0x3d118b08, 
    0xbd842e9f, 0x3c6d43d2, 0xbe0472ae, 0xbd8c6fa2, 0xb8fa3b7a, 0x3decf910, 0xbe5b199a, 0x3e27d910, 
    0xb70ffbe4, 0xbe5c2c6d, 0x3d1126a3, 0x3dda1e1b, 0x3e29dd92, 0xbe5ef5fa, 0xbe2f2a32, 0xbf27f472, 
    0xbcc58dfa, 0xbe5c60c7, 0x3e66c7ff, 0x3e5d2127, 0xbf000a70, 0x3e9c2605, 0x3e6514ba, 0xbe5347d8, 
    0xbe806ac1, 0x3f193a5f, 0xbdc9cfe5, 0xbeeb82de, 0x3eed865a, 0xbe963753, 0xbd102a2b, 0x3d975fb4, 
    0xbe981011, 0xbe94e78d, 0x3e904e2e, 0xbe10a43a, 0x3e475c7c, 0xbeabbd45, 0x3f14cc56, 0xbe790f3f, 
    0xbdf33f6b, 0x3e49effe, 0x3e7da379, 0xbded5271, 0x3e311075, 0xbdf73c5e, 0xbea97f59, 0x3e1b9887, 
    0x3e940d49, 0x3bd3e0f8, 0xbe01dc43, 0x3e33823d, 0xbe902fce, 0x3bcc8403, 0x3e45caf2, 0x3d2d800c, 
    0x3d4a5ce4, 0x3e8561ee, 0xbda7e176, 0xbd43738a, 0xbe295507, 0x3e1d6d7a, 0xbe2377a6, 0xbda7311b, 
    0x3da0d8a6, 0x3d11af1c, 0xbc6041b1, 0x3e54121c, 0xbcba72f0, 0x3dedb95b, 0x3e2e69ca, 0xbd0edbc6, 
    0xbde77f96, 0x3dbf2a81, 0xbd9a0c83, 0x3dfe12dd, 0x3db007ce, 0xbdc5b2c8, 0xbd9c3226, 0xbd0c6d69, 
    0xbd20b0e5, 0x3cde11f3, 0x3dce2f69, 0xbe7d31e2, 0xbdb105be, 0xbe17b17f, 0x3ca1ac7e, 0xbe5f1b0d, 
    0xbcda53c3, 0x3da4d16b, 0xbd44f501, 0xbd2635c2, 0xbe4b8c13, 0xbe79488a, 0xbdcdf3f4, 0xbe723a48, 
    0x3e7dbfd9, 0x3d519d3e, 0x3e9be553, 0xbd41fd1c, 0xbe906b2b, 0xbcadbfe6, 0x3e8ec4ad, 0x3db40a34, 
    0xbe9f45be, 0xbdee1033, 0xbd5454fe, 0xbe4d8e79, 0x3c75e945, 0xffffbcfe, 0x00000004, 0x00000040, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0xffffbd4a, 0x00000004, 0x000000a0, 0x3f1ec565, 0x3f5bdd00, 0x3d9e0b22, 0xbfd348fa, 0xbec29f58, 
    0xbea61a19, 0x40444a6c, 0xc00afaf5, 0x3fa176d8, 0xbf9b85ff, 0x3dc2083b, 0x3fbd25f5, 0x3f6b3732, 
    0x3f2b0b95, 0x3ee67fb1, 0xc031c868, 0xbf0d31c2, 0xbda58958, 0x3cc2f5ae, 0xbd638e04, 0xbfeb6834, 
    0xbd5bc0f9, 0xbe47db8c, 0x3ec0f2e8, 0xbf700f78, 0xbf1b0a26, 0x3f600f2d, 0x3fa599b3, 0x3ee935bb, 
    0x3f12e5a5, 0xbf3e1eba, 0xbf000cf4, 0x3e60cc81, 0xbfea465f, 0x3fd6a3b6, 0xbf6b5795, 0x3e08437a, 
    0xbedab38e, 0x3f90cf51, 0x4005a709, 0xffffbdf6, 0x00000004, 0x00000a00, 0xbeee9548, 0xbde8842f, 
    0x3ea83e0b, 0xbefafc80, 0xbe3cf621, 0x3ee329ec, 0xbd6961b2, 0x3eb29cd4, 0x3eef90ad, 0x3efea117, 
    0xbe051c55, 0x3f548856, 0x3f0f0237, 0x3e841cb0, 0xba71db7a, 0x3efd3376, 0xbf2dbb23, 0xbe416b3c, 
    0xbe8d4dc5, 0xbea038e8, 0xbde2dc3c, 0xbf59acdd, 0xbf143a61, 0x3e62edd2, 0xbf121630, 0x3fa9c5d5, 
    0xbe12144d, 0x3f81ca75, 0x3f5713fa, 0xbdc30230, 0xbec6c1c7, 0x39f7f11a, 0x3ec85f71, 0x3d491e23, 
    0x3f63ad06, 0xbec73b88, 0xbf201fb6, 0x3eab7b84, 0xbda7c75d, 0x3e970be2, 0x3db37a38, 0xbe46e410, 
    0xbef1655c, 0x3e66bcf0, 0x3efd48eb, 0x3f1c656c, 0xbefae7b6, 0xbee45636, 0x3fab8af6, 0x3ee2f638, 
    0x3f1314db, 0xbd8a51b4, 0x3edd6a2c, 0xbe228d15, 0x3ec8c2f8, 0x3e98c946, 0xbf2c2764, 0xbe45aaec, 
    0x3e036738, 0xbf636454, 0xbfd798e7, 0xbfb979af, 0x3dc03c04, 0x3efd0c18, 0xbea2ee63, 0xbe615a7a, 
    0xbf0e87ab, 0xbec4023f, 0xbf6a8e72, 0xbe9abb32, 0xbf2128e8, 0x3fd8508b, 0xbd6c96e7, 0x3f78cfae, 
    0x3e84bc43, 0x3f82c188, 0xbe07ea20, 0xbedcaa58, 0xbf1585ed, 0x3e9ffbad, 0xbe13f990, 0x3f198c2b, 
    0x3f5d7af8, 0xbf3db90e, 0xbee030ea, 0x3ec71b8d, 0xbf68582d, 0x3f6dc62b, 0xbe2a90d7, 0x3f7a489e, 
    0x3e89302a, 0xbe510b32, 0xbec15bed, 0x3e9185d6, 0xbf15e17c, 0xbe0e452f, 0xbfc4ee1b, 0xbf02824b, 
    0xbf619502, 0xbf2344bd, 0xbe06716f, 0xbf1f95b6, 0x3f33d8ea, 0xc0100ed9, 0xbf0dbef5, 0x3ea6d31e, 
    0xbf47aff8, 0xbf2c60c0, 0x3f8de820, 0xbea01025, 0x3ea7b145, 0xbfaba4af, 0x3fc74259, 0xbe88a285, 
    0xbefb1951, 0xbf88a2ef, 0xbf0d5ae8, 0xbf4e1581, 0x3ef09910, 0x400fe668, 0x3f57984d, 0x3eafa61f, 
    0x3f97d1d0, 0x3f893022, 0xbdd45b03, 0x3f0444d2, 0xbf872fb5, 0x3f12a2b7, 0xbec6df02, 0xbe32b8d4, 
    0x3ec9d09c, 0xbe831691, 0xbf01ab28, 0xbe2bfaad, 0xbeb015ad, 0xbf12c04a, 0xbc3465fc, 0xbe92b0c7, 
    0xbf0b3a5e, 0x3e45f96f, 0x3ecac9c4, 0x3f2648f2, 0x3c7ce854, 0x3f73430a, 0x4012f878, 0xbf7adf12, 
    0x3fc58aa1, 0x3f7eb65b, 0x3ddc5172, 0xbef073aa, 0xbe8d3aa6, 0xbe382688, 0xbf69022b, 0xbf36c7c9, 
    0x3f9da96e, 0xbf8e61da, 0x3f4cdded, 0x3daec6ef, 0x3f01d615, 0x3ed1f610, 0xbe9eb4ba, 0x3f8f9b85, 
    0x3f340aef, 0x3e848244, 0x3e044e78, 0x3f34274a, 0x3f7b19bf, 0x3d6ea1ea, 0xbf00d63e, 0xbeb2d3f1, 
    0xbc13b39e, 0x3e481a87, 0xbed18bae, 0xbf2d6e53, 0xbebdedec, 0xbe5cfacd, 0x3d889836, 0xbf6ae5f8, 
    0xbf56f81b, 0xbe263ebd, 0x3e40ff3f, 0x3f5608ed, 0xbe3a5dcf, 0xbf75f6ef, 0x3ed1eb1b, 0x3ee31455, 
    0x3f33ca17, 0xbf2756c0, 0x3e931ea7, 0xbc9ccbbe, 0xbe5f2d3b, 0x3f6e4f0a, 0x3ea3720f, 0xbeb47218, 
    0xbf386c0c, 0x3eac5f72, 0xbef2390b, 0xbe0aad85, 0xbe885d23, 0xbfa2174e, 0x3e95fcbf, 0xbd566eb4, 
    0x3cc86097, 0xbf1280ea, 0x3e24f408, 0xbde3bdc2, 0xbdbc92a0, 0x3f7f848f, 0x3f8768f6, 0x3f0f69ff, 
    0x3ebd751e, 0x3fa209ae, 0xbf0d10eb, 0x3eedab94, 0x3f095db1, 0x3da5cfa3, 0xbee9445b, 0x3dc3d33e, 
    0xbfbec4f2, 0xbdff7d72, 0xbc6d1a9d, 0xbf3fd8e6, 0xbeacef08, 0x3fa2880a, 0x3f1fa375, 0x3e6ea025, 
    0x3ed253a6, 0x3eae004a, 0xbf4cb2eb, 0x3ecb5852, 0x3e926738, 0xbe3cc023, 0xbebafea2, 0x3e1f0069, 
    0xbedadcfd, 0x3e8fcced, 0x3c55f8a1, 0x3f44c116, 0xbf89cd08, 0x3f5e8056, 0x3fb1ba3c, 0xbf2edcb8, 
    0x3f8bdcfd, 0x3f132219, 0xbed93d7b, 0xbf89bb3d, 0xbe45c105, 0xbdf115e6, 0xbef56899, 0xbfe4f20c, 
    0x3f603fa8, 0x3f10e8b2, 0xbfbd1d6e, 0x3fb8f9de, 0x3f65eac5, 0x3ed0a644, 0x3f236028, 0x3e9805ed, 
    0xbf14b73f, 0xbf888382, 0xbf3cad20, 0x3e2356f7, 0x3e9c3fd2, 0x3f9b518d, 0xbf0bd3fb, 0x3f046bb3, 
    0xbe84fa7f, 0x3e97d55c, 0x3e23ce8c, 0xbd9c9c3c, 0x3eb42373, 0xbf257a53, 0x3ea6f6b8, 0xbf831251, 
    0x3f107873, 0x3ee6a959, 0x3f09cb9d, 0xbf3783ee, 0x3ef23576, 0xbf15bb96, 0x3e643584, 0xbf898b50, 
    0x3f37ca90, 0xbf04e4d7, 0xbdc34dca, 0xbeada2d3, 0x3e9dc729, 0x3f07e118, 0x3e9cf86b, 0x3ecef5df, 
    0xbcdcd917, 0xbe734e5f, 0x3f0a8b3e, 0x3c3f3ef9, 0x3f1df5f7, 0x3f877937, 0x3f070cb7, 0xbfc544c0, 
    0xbfdbd5b6, 0x3e70021f, 0x3ee9bcbe, 0x3e9595e9, 0x3ebedf0e, 0x3f1adb6c, 0x3d4e7f2f, 0x3d429cc7, 
    0xbec4fdd8, 0x3f6b1346, 0xbc0c90c2, 0x3f0ae03f, 0x3eaf5367, 0x3f30958f, 0xbe7685f0, 0xbe9882c7, 
    0xbda88e8d, 0xbed2b100, 0xbe7f87aa, 0xbe4a2d72, 0x3e9bb724, 0xbe611e6e, 0x400e0a33, 0xbf582a9d, 
    0x3f1268eb, 0xbef9fd92, 0x3f5d73b2, 0xbf10f2ae, 0x3eb8ccbb, 0x3f6f5f7e, 0xbf8f4ce3, 0x3f784934, 
    0xbe70de07, 0xbf2cfab9, 0xbffd973f, 0xbd3ecf0f, 0x3f43941e, 0xbe27b87e, 0x3f04ed15, 0x3e0dc9a2, 
    0x3da4beb6, 0xbe8d1865, 0xbf8107eb, 0x3e81f437, 0x3d91348a, 0x3e9b3a01, 0x3e938f96, 0xbeb175cf, 
    0xbf1539c3, 0x3ed48e56, 0x3f07c80f, 0x3e69f730, 0xbf0f12b1, 0xbcd7ee17, 0x3cfb9dc1, 0x3ddb3437, 
    0x3ea2c922, 0x3f438a61, 0x3e89468d, 0xbf270ff3, 0x3f15b300, 0x3e72f49d, 0xbf0bbb74, 0xbea65716, 
    0x3e06aca4, 0xbe8ca80b, 0xbf110339, 0xbfb52fb4, 0xbed4e274, 0x3f0108ad, 0xbcc8c9ae, 0xbda5ac70, 
    0xbb50ac7a, 0x3f421d9d, 0x3eedf2dd, 0x3dfb9c3d, 0x3f648cfa, 0x3e629616, 0xbde54388, 0x3c5ad2bd, 
    0xbec922ac, 0xbe06dc01, 0xbe808c3d, 0x3ebc9f58, 0xbd731610, 0xbe8d8ac3, 0x3faff005, 0x3ea8fd21, 
    0x3ed4df52, 0x3f0dc62c, 0xbecdc38a, 0x3e37c080, 0x3ed79796, 0xbf1739f4, 0xbd4f7f05, 0x3ef4c49e, 
    0x3dc2aa42, 0xbee3f17d, 0xbf478ada, 0xbe4a77db, 0x3fb016e6, 0x3e7c03cc, 0x3e847c32, 0x3f3845c1, 
    0xbf099623, 0x3fd7aa8f, 0xbf8214cd, 0xbdcc2b53, 0xbeba552e, 0x3d8bec87, 0xbf57b117, 0x3ebb78e8, 
    0x3f25f3ef, 0x3f156e4d, 0x3e460128, 0xbe01ed9c, 0xbea36b37, 0xbe31b762, 0xbf0694d0, 0xbecefb98, 
    0x3ec82fb8, 0x3c754e8e, 0xbe09e9c4, 0xbedc7d09, 0xbd2a53ce, 0xbf90bf3c, 0x3e7b7e75, 0x3db886b7, 
    0x3e843c1e, 0x3f4c96e4, 0x3dbc2961, 0xbf02f4d0, 0xbe91d986, 0x3f9fea10, 0xbf90fbd7, 0x3cfb2df3, 
    0xbfb45f4a, 0xbd91c5d6, 0xbf679e42, 0xbe18c8f4, 0xbf30902c, 0xbf8598b6, 0xbe36f49f, 0x3ed3283a, 
    0x3ec09186, 0x3d9295ed, 0x3f5a2b0e, 0xbeb1ec6c, 0x3e213eee, 0xbeac526f, 0xbf173e79, 0x3e1f0fac, 
    0x3ed10f0f, 0xbf7ea5f7, 0x3e5e18f2, 0xbedfbc1b, 0xbf69eeb7, 0xbea8a958, 0xbf109eee, 0xbf7652fc, 
    0xbe74df9c, 0xbf085a57, 0x3ea8bfc5, 0x3e069744, 0xbd822eee, 0xbee756b0, 0xbef2e3a5, 0xbf06d7a2, 
    0x3e4984b1, 0xbf589e51, 0xbdef2ce5, 0xbde0a9bc, 0x3e61496a, 0xbf33228a, 0xbe831cd1, 0xbf2206b7, 
    0x3e999b67, 0x3e8e835f, 0xbef443c8, 0x3f31369a, 0x3f0f2829, 0x3f81d818, 0x3e91fc00, 0xbbff95e2, 
    0x3e80e9f9, 0x3e2bd851, 0xbd16cab9, 0xbf107bf4, 0xbc2d26b1, 0x3f0f88c5, 0x3fd18fe7, 0xbfd4ef0e, 
    0x3f3efa9f, 0xbfbfa1e5, 0x3ed2623f, 0xbf2e5987, 0x3e104467, 0x3f9e452b, 0x3e868e3f, 0xbe1758a2, 
    0xbce63584, 0x3f67f577, 0x3d29b3f2, 0xbe87aa70, 0xbfaa5def, 0xbf015be0, 0x3f9ccd71, 0x3f170219, 
    0x3ce8f429, 0xbf01de74, 0xbef322ce, 0xbf6a8cb6, 0x3ec93db1, 0x3f05d6ad, 0xbf55b72d, 0x3f404346, 
    0xbfc8974a, 0x3f1ef263, 0xbf8215d7, 0xbf2565ca, 0xbf2b5521, 0xbf35e061, 0xbd6f09f4, 0x3fb9753f, 
    0x3eb129b0, 0x3f9a2726, 0x3ec9ddf9, 0xbe4464de, 0xbecdeefa, 0xbe93ee36, 0xbedac8c9, 0x3fcbcf9b, 
    0x3f9e52f0, 0x3c5fe4f5, 0xbf7586c6, 0x3f266663, 0xbf4a6c62, 0x3e98cf54, 0xbe7fb8f5, 0x3fce730f, 
    0x3dfd3ca5, 0x3f15b63f, 0xc02575f2, 0xbfb74044, 0x3f592ac6, 0xbf88b1d7, 0xbe5aebcb, 0x3f814a00, 
    0xbe9c6434, 0x3f46889b, 0x3d2c87eb, 0x3fd6ec9d, 0xbf174611, 0xbe411c0f, 0xbef734df, 0x3f33cf02, 
    0xbf89a68e, 0xbf8f872d, 0x3f1d61bc, 0xbf640e26, 0xbf00d3ce, 0x3f778dff, 0x3f24ce1e, 0x3f25d35b, 
    0x3de2af15, 0x3ec15d46, 0xbfb94f82, 0xbfa0be2e, 0x3f8b3212, 0x3e15759f, 0xbf1594bd, 0x3f8a8463, 
    0xbef7e881, 0x3eccbc84, 0xbf8295d5, 0xbecc6cda, 0x3ee1654e, 0x3eb7506e, 0x3ee3cd58, 0xbe191e14, 
    0x3eeeaeed, 0xbe82bf0a, 0xbd79557b, 0xbe5dc80e, 0xbf754367, 0xbec2113d, 0xba2690d7, 0xbe5792dd, 
    0xbf3a5995, 0xbe90488c, 0xbe7c31ca, 0x3ec9bca8, 0x3e39a222, 0x3f0c8c80, 0x3ee380cb, 0x3efd1ffe, 
    0xbefe39c3, 0x3f819861, 0xbdb08e8e, 0xbeba4d7b, 0xbe3dc234, 0x3f1a0120, 0xbecaddf6, 0xbece0446, 
    0xbe2fbf21, 0xbf3283fb, 0x3f09a801, 0xbfa07cec, 0x3e99206e, 0xbdc7527f, 0xbfacdbe9, 0x3f821fae, 
    0xbf9f2b0d, 0xbf433589, 0x3f75c061, 0x3f3c4667, 0xbf63f533, 0xbee2b551, 0xbe951895, 0x3f336f02, 
    0x3f615dd0, 0xbf164c53, 0x3e82fd53, 0xbc25d167, 0x3e0cfaa9, 0x3e4b364a, 0xbdd11af8, 0xbff31bd7, 
    0x3eb6979d, 0xbfa75cb8, 0x3d24f750, 0xbe088d84, 0x3ebfd84d, 0xbf40d3a2, 0x3f460e54, 0xbe04d8d5, 
    0xbfa31b9c, 0xbef21a84, 0x3dd63fe2, 0xbf0e9281, 0x3f305c7f, 0x3f271c98, 0xffffc802, 0x00000004, 
    0x0000000c, 0x00000001, 0x0000004b, 0x00000010, 0xffffc81a, 0x00000004, 0x00000010, 0x00000001, 
    0x00000096, 0x00000001, 0x00000010, 0xffffc836, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 
    0x0000012c, 0x00000028, 0xffffc852, 0x00000004, 0x00000c00, 0x3f31810f, 0x3ca220a5, 0xbea101c8, 
    0xbea3b48c, 0xbe23aed3, 0xbebdf4f2, 0x3dfbb2b4, 0x3e192109, 0xbdf96ed2, 0x3ec6f0df, 0xbe597ad9, 
    0xbe39cb43, 0xbe3346c5, 0x3ee0a451, 0x3e2db104, 0xbdf42b9e, 0x3dd13536, 0x3da82880, 0x3d94fb09, 
    0xbdb9f8d7, 0xbc5bb4a8, 0x3db6c615, 0x3ee7e6ac, 0x3eb59107, 0xbea8737f, 0xbe13511e, 0xbeabef89, 
    0xbed3f8d2, 0x3da5cd3f, 0x3ec0de13, 0xbdaaabe2, 0xbddb3588, 0xbe2dd308, 0xbeb7ec15, 0xbe2cbda5, 
    0xbeb24437, 0xbce6bbc2, 0x3d923574, 0x3ed9a1fe, 0x3dbe813c, 0x3a2121e8, 0xbdbfc642, 0x3e97729b, 
    0xbde04b68, 0x3d66d397, 0x3b191bf4, 0xbdaf25e2, 0xbbec8062, 0x3d7537dd, 0xbe830960, 0xbe63b910, 
    0xbe199eee, 0x3e01a3a0, 0xbe1158eb, 0xbe0a2fa4, 0x3e46d822, 0xbe010677, 0xbe656067, 0xbe3fa085, 
    0xbe862fea, 0xbe8be7bf, 0x3cf88039, 0x3f10e547, 0x3e82b864, 0xbe4cdba3, 0x3d6888f3, 0xbe2e3094, 
    0x3e81ff9d, 0xbeaa1dbb, 0x3da8a9e3, 0xbc665559, 0x3e7aebcb, 0xbe02e0c9, 0x3e971195, 0xbc28fe0c, 
    0xbca81b93, 0xbe46b40c, 0x3dba715c, 0x3e965914, 0x3e177f83, 0x3e06b94c, 0xbd754af9, 0xbdfc9799, 
    0x3d37a296, 0x3daaa2c5, 0xbe7b3498, 0xbe804bd9, 0xbc00eb22, 0xbe4c2c0b, 0xbe7cb2ca, 0x3e44c326, 
    0x3deb7225, 0x3e8c69a1, 0x3d73f72a, 0x3f00e6a2, 0x3e97a9fc, 0xbe53a0dc, 0xbe295c15, 0x3d009cc5, 
    0xbd9209bb, 0x3dd47fed, 0xbdd4a364, 0xbb08b1c1, 0xbe8d60e7, 0x3e8822dd, 0x3e489028, 0xbcdbab34, 
    0xbbc86620, 0xbe2f1b48, 0xbdebdd00, 0x3ec6e0eb, 0xbe86e1df, 0xbd851a8a, 0x3e041194, 0xbe1b1dd7, 
    0x3e26c0f0, 0xbe355841, 0xbe09c518, 0xbe0c4e37, 0x3dc84822, 0x3e75cbad, 0xbd5dd965, 0x3ea792bc, 
    0xbe806c04, 0xbd1ea479, 0x3d4f697f, 0x3ef8ff4a, 0xbe7a0c37, 0xbe4757a5, 0x3e68b1fd, 0xbe2c6e7c, 
    0x3de75717, 0xbda45bd3, 0x3e6711c3, 0xbe771627, 0x3e1eb997, 0x3d2be099, 0x3d3f0594, 0xbbd37e42, 
    0xbdba38ec, 0xbe5b6e98, 0x3cb2e089, 0x3df7dd15, 0xbeb5c2e1, 0x3deb4cf9, 0x3d9f5185, 0x3d8cb01a, 
    0x3e0d12cc, 0x3df66a60, 0x3df7bb00, 0x3d6f1663, 0xbdab14ee, 0xbe1d0ce1, 0xbe174ddf, 0x3e23ec9b, 
    0xb9a6dd81, 0x3df5c0f2, 0x3e640f8b, 0xbcaa65ec, 0x3dd80135, 0xbd42ca2f, 0x3e2e9301, 0x3ce4e85a, 
    0xbe3213a0, 0xbd197c21, 0x3e1bd483, 0x3e0290e7, 0x3d77f2ab, 0xbd42792a, 0xbe0be974, 0xbdf45d93, 
    0xbcf204ed, 0x3de53a08, 0x3e5f3f14, 0xbd56b471, 0x3df33d67, 0x3d8bb34b, 0x3dc159c0, 0xbd435fdb, 
    0x3e2bacdc, 0xbddbcb9d, 0x3d395fc4, 0x3de7ac21, 0x3e021648, 0xbe712fef, 0x3e1ae472, 0xbca28368, 
    0x3e3abab0, 0xbd89a241, 0xbd06bebb, 0x3d850478, 0xbd9d8ec2, 0x3e733ccc, 0xbdc19a1c, 0x3df4700d, 
    0xbd27ff07, 0x3eb414bb, 0xbda8edd6, 0x3e18da13, 0x3e99f62c, 0xbe973dfb, 0xbcb58f49, 0xbe78cb45, 
    0xbd92a460, 0xbd3c8751, 0xbe2ac8c3, 0xbe1ac420, 0xbe509f7a, 0x3e7606b2, 0xbe222c60, 0xbc87cfc9, 
    0xbd94bd9d, 0x3e948776, 0xbe0ed2af, 0xbdfa9441, 0xbddc6e1a, 0xbe1e17f8, 0xbe7a1da6, 0xbd1a4440, 
    0xbd392041, 0xbd082300, 0x3da04bf3, 0xbe67ff3f, 0xbdc5c38a, 0xbcb8ffcd, 0xbe499a59, 0x3e52e60c, 
    0xbadfa60b, 0x3d5c7435, 0x3d0df515, 0x3dd9e296, 0x3dbd7b97, 0xbda6c961, 0x3e0d555d, 0xbd780151, 
    0x3da5b831, 0xbe619165, 0xbd111dd7, 0x3e32b4ff, 0xbe6bc5fa, 0x3f05ec19, 0x3cce2f67, 0xbd60697f, 
    0x3e9b31d3, 0xbd7185a1, 0x3e3421a2, 0x3dbc20dc, 0x3e9c73c2, 0xbe74660f, 0x3cf80d14, 0xbec5f02f, 
    0xbd043a42, 0x3e1ae3cf, 0xbe7f5eea, 0x3debc39b, 0x3d0e606a, 0xbde0c92b, 0xbe84ea35, 0xbe9c8c8e, 
    0x3d360cbc, 0x3ea7882b, 0xbdb7bf4d, 0x3e7d1817, 0x3e62c5f8, 0xbcc75bdf, 0xbddbf2c9, 0x3e418370, 
    0xbd4262bf, 0xbd906d69, 0xbe429b70, 0xbe35c6b7, 0xbe8e45ee, 0xbd3e9835, 0xbe4905c7, 0xbe2d7c92, 
    0xbd5521fb, 0xbd74d11c, 0xbe29292e, 0xbe1acb70, 0x3e858d44, 0xbe28e8e8, 0xbe8ce4dc, 0x3e6732ab, 
    0x3d6b46da, 0xbdfb067f, 0xbe82dd3d, 0x3ced6819, 0xbe14117a, 0xbe3ae6eb, 0x3e1edaea, 0x3df43a1a, 
    0x3e100580, 0x3e12fbf5, 0x3cf6d1cd, 0x3c4b0737, 0x3d579870, 0xbda0065f, 0xbdfd8feb, 0x3ccd6127, 
    0xbd91309f, 0x3e87435d, 0x3c9e9bf5, 0xbd950623, 0x3ce9da43, 0x3d7c3b40, 0x3e2eba3b, 0x3dad4590, 
    0xbde94b5e, 0x3cf1d0af, 0x3d296dc0, 0xbd9c71fa, 0x3cf50179, 0xbd3ed5ce, 0x3cd0e9e8, 0xbbb1d1a2, 
    0xbd7ac319, 0x3e7b4497, 0x3ddcdf56, 0xbd84fcb2, 0x3e32d2e2, 0xbdcd6904, 0x3e5e3179, 0x3e38bf14, 
    0x3d8b27de, 0x3d51b6ea, 0xbc1d6280, 0x3b849720, 0xbe4c7860, 0xbe145ede, 0x3d736a96, 0x3e381ad6, 
    0xbce7fa6c, 0x3e1e427b, 0xbde15e93, 0x3dcd3fcd, 0x3cb228d1, 0xbd49a54a, 0xbe0db7af, 0xbd28b418, 
    0xbe147ac2, 0x3cea0de3, 0x3db797cc, 0x3d845f15, 0x3e18d75f, 0x3de1c9bb, 0x3dacf412, 0xbd0f3977, 
    0xbd23abe4, 0xbde8400f, 0xbdacce61, 0x3daf571c, 0xbe3fe68e, 0x3e5268b8, 0xbe1b7b31, 0xbe1e3438, 
    0x3d8d08c4, 0x3e3420f8, 0xbe3519ff, 0xbd4406b8, 0x3cef59a8, 0x3c09c7ce, 0x3df4a0de, 0xbd701f71, 
    0xbde64572, 0xbdffc558, 0x3d0eea55, 0x3d9d5450, 0xbd7679a9, 0x3c0a2889, 0xbceca024, 0xbd2c5808, 
    0x3da26dd4, 0x3e196787, 0xbe14e99a, 0x3c12502c, 0x3d2ba292, 0x3c40cb4e, 0xbb55735f, 0xbdfb82f6, 
    0xbda0a14e, 0xba509ba3, 0xbd1438b5, 0xbe27d84c, 0xbe4341a6, 0x3e8c3578, 0xbe3ae280, 0x3de3335b, 
    0x3df049f3, 0x3e3645ea, 0xbe3967e9, 0x3c87e491, 0x3e89afff, 0x3e09e2e0, 0x3e56b0ea, 0xbe0e73be, 
    0x3dd8b468, 0xbe0e485d, 0xbe0be552, 0x3e4647cb, 0xbe64fbe0, 0x3ea68490, 0x3ac3e509, 0xbd3f0166, 
    0xbe351ebc, 0x3d729b4c, 0xbe281ce6, 0x3d69f14f, 0x3e946760, 0xbe541a23, 0x3d05b47f, 0x3c95323d, 
    0xbe1cab91, 0xbe5cec98, 0x3d2506fe, 0xbdc54fdc, 0xbe2a49d4, 0x3cdd92df, 0xbd55e545, 0xbc4c6d3e, 
    0xbc3d1b1b, 0x3e106655, 0xbd979ffe, 0x3e0f4b14, 0x3e3a19a9, 0x3d5dbc52, 0x3de2b762, 0xbd09fca1, 
    0x3d9f5be9, 0xbe2249ae, 0xbe0d60f0, 0x3e3b8b5c, 0xbd2563d3, 0x3e85c9e6, 0xbe6bfe22, 0x3d356ae9, 
    0x3dff628a, 0xbe1cf681, 0x3d598301, 0x3e37fd62, 0x3e1aa3d1, 0x3e28a5d7, 0xbd0a50c9, 0xbe601b93, 
    0xbd9a646b, 0x3e8a6e47, 0x3e815f6f, 0x3c00ece2, 0x3f0a0595, 0xbdae9824, 0x3e6a7957, 0x3d24d199, 
    0x3bf53426, 0x3c8e5ce5, 0x3e4453aa, 0x3e1139d4, 0xbe6fcbb1, 0xbe1288a4, 0xbe6d8d14, 0xbddcafdc, 
    0xbe3d7ea0, 0xbe2bd458, 0x3e6ffa31, 0xbe13584a, 0x3ed6a13c, 0x3e0e0350, 0x3dd8b2be, 0x3dd7650a, 
    0xbccb259a, 0x3e359ee0, 0x3e63c383, 0x3e7ec430, 0xbe189b74, 0x3d567725, 0x3e215809, 0x3dd6da3c, 
    0xbd5a416f, 0x3e221d8f, 0x3ed5fc97, 0xbb654484, 0x3d86682e, 0x3d962f97, 0x3d0c7ce8, 0xbb889f0b, 
    0x3d911633, 0x3d779762, 0xbca0cd09, 0x3e4d853f, 0x3e1081b9, 0xbdf14577, 0x3cd19480, 0x3dc3e89c, 
    0x3dc8cc95, 0x3dacf541, 0xbd3f7611, 0xbdeac962, 0x3cf5092c, 0x3c56ff58, 0xbd492f1c, 0xbd54cf2f, 
    0x3e2772b5, 0xbd798229, 0x3cd8ff42, 0xbd05d9e5, 0x3c7a6d1b, 0xbe038d6e, 0x3dd178a6, 0xbd0b8e09, 
    0x3dc84dfd, 0x3de42fc5, 0x3d0e0d76, 0xbda097fb, 0xbd33fddf, 0x3dfa6768, 0x3e2f0379, 0x3e076dbb, 
    0xbd4b22c3, 0x3e1a315d, 0xbc60ae8d, 0x3e167593, 0x3d8a833d, 0xbca7b117, 0xbdacadb0, 0xbd2bbded, 
    0x3db24215, 0x3cca8faf, 0xbde31b6b, 0xbc6190ff, 0x3db6afc0, 0x3da0ec05, 0x3d7fd15e, 0x3d1d85dc, 
    0xbd241519, 0x3e57df82, 0x3e57d002, 0xba580de8, 0x3d2ece0b, 0x3cbfa54e, 0x3b7673a6, 0xbdb83578, 
    0x3e07ad62, 0xbce3fbeb, 0x3d5525e4, 0x3dc7602c, 0x3dc7cc95, 0x3d8b417c, 0x3e59b763, 0x3e0977f2, 
    0x3d463d54, 0xbdb3b0f7, 0x3bebb958, 0x3d63fe04, 0xbd8c7d68, 0xbc88bb5a, 0x3c91b7e0, 0xbb73a4b0, 
    0x3d482e6a, 0x3e6cf306, 0x3ddcaf43, 0x3e578e16, 0xbd9865e0, 0x3c79b1ec, 0x3d908129, 0x3ddbde8e, 
    0xbcbe4a62, 0x3d1f8248, 0x3e90ae96, 0xbe62b4c4, 0x3d4dfcdf, 0xbd0dcd9b, 0x3dc0281b, 0xbd2e520b, 
    0xbd2fe594, 0x3deb864a, 0xbd4ef387, 0xbd2bf932, 0xbe15980e, 0xbe43d660, 0x3e140a1d, 0x3d1d97c4, 
    0x3e32f40a, 0xbcfca8b2, 0x3d5f5ed1, 0x3dc0f056, 0xbe2a2bc3, 0xbe6c7677, 0x3e5e8f0a, 0xbd898e71, 
    0xbcef6fcb, 0x3da8077c, 0x3e08de67, 0xbdf5b3ba, 0xbdc147af, 0x3db1c9b7, 0xbd229b5c, 0x3e72988c, 
    0xbd6d8eeb, 0xbc77470f, 0xbcbe551f, 0x3e242da7, 0x3c0c8c17, 0x3df68e7f, 0xbddc498e, 0x3de954dc, 
    0x3e2674b8, 0x3e00fecd, 0x3cb26980, 0xbd5b1ff3, 0xbd67b201, 0xbdaabbc6, 0x3e95821e, 0xbd067eb0, 
    0xbdda35f9, 0x3ddfbf48, 0x3e61eb80, 0x3d6def7b, 0xbe240cce, 0xbe07f6ea, 0xbd2610c5, 0xbe310aad, 
    0x3d586996, 0x3d7bfd80, 0x3d6e0ff2, 0xbe088ecb, 0x3d52b0b5, 0x3dca27eb, 0xbeaabfdc, 0x3c4de689, 
    0x3e55c80e, 0xbdd83108, 0xbe5508ea, 0xbe28eaa6, 0x3e22be3b, 0xbdbe87c0, 0x3d862a6c, 0xbe59ee15, 
    0xbd7b81a1, 0xbdc292bf, 0x3ca6260f, 0xbe442c84, 0xbce42038, 0x3da32df0, 0xbe5ffa6f, 0xbd3975cf, 
    0xbdf6987d, 0x3dfb58d9, 0x3dc76bbe, 0xbbd4ba7c, 0x3e7da2d7, 0xbddf2a05, 0x3ced0b04, 0xbe87a8d4, 
    0xbe1963ff, 0xbd8d6966, 0xbd0b6e7d, 0xbe5eccf3, 0xbe3bccca, 0x3dca8a2c, 0x3d14e9eb, 0x3d907650, 
    0x3de96e3a, 0x3d9e8059, 0xbd863af1, 0x3d75f257, 0x3e4c5573, 0x3debea33, 0x3d11549a, 0xbd64f614, 
    0x3b645e0a, 0xbe4f14e4, 0x3e075705, 0x3c4b7fe0, 0x3da6c4eb, 0x3e14f0b8, 0x3d343e63, 0x3c911734, 
    0xbc50e7bc, 0x3dc53470, 0x3ddb9d15, 0xbd1e5e02, 0xbd219c00, 0xbd3909de, 0x3df3b281, 0xbdebb670, 
    0x3d51146c, 0x3e04c9f1, 0xbd322790, 0xbd8f58d0, 0x3ca3623d, 0xbbca3c0a, 0x3d869058, 0x3de84bf7, 
    0x3deef431, 0x3d709e95, 0xbd9dce8a, 0x3e5404af, 0x3dce1b1c, 0xbd9bbd39, 0x3d860560, 0x3bad4b59, 
    0x3d901433, 0xbd183208, 0xbe1d8848, 0xbde99e65, 0x3d8d605d, 0x3e0b7861, 0x3e035c3c, 0x3c97cd5c, 
    0x3e12b19f, 0x3dc2eb27, 0xbc9923b6, 0xbc5b2f54, 0x3b33b19a, 0xbe21822c, 0x3d9b8073, 0x3d940a99, 
    0xbd5bf44a, 0x3e2ea460, 0x3dddcc54, 0x3db2ccd2, 0xbd5512d8, 0xbccff33e, 0xbd0aee3a, 0x3e154dee, 
    0x3dd629b1, 0x3e0bc080, 0x3dae9f6f, 0x3bf5e3e0, 0x3e169756, 0x3d05ceac, 0x3cde0248, 0x3dbd452a, 
    0x3e133e42, 0xbc4d7d4a, 0xbdfcf465, 0x3dd13f00, 0x3dd9cd34, 0xbd8c1ceb, 0x3ddfa016, 0x3e218b2b, 
    0xbc9aa8a4, 0x3db5317c, 0x3df59c60, 0x3dfac897, 0x3d0c4583, 0xbd918db7, 0x3d59dfd1, 0x3d6baa75, 
    0x3d549f18, 0x3e2197da, 0x3dfad75a, 0xbd96313e, 0xbdaa8f6d, 0x3d26125e, 0x3e21db3f, 0x3d6acd1f, 
    0x3dc09dbb, 0xbcbcb022, 0xbd6392ca, 0x3d66c13d, 0x3dca2dfd, 0xbe22f000, 0xbd8c2861, 0xbd985b32, 
    0x3c0278be, 0xbcf2f752, 0xbe11d73e, 0xbdd5077e, 0x3e007e9c, 0xffffd45e, 0x00000004, 0x00000c00, 
    0xbe10bbd5, 0x3e10e782, 0x3e4616a2, 0xbe8f939a, 0x3dedaadf, 0x3e93b37d, 0x3e89e11b, 0x3eaada1b, 
    0x3e3c5c04, 0x3e99f27c, 0xbe5557aa, 0xbd8e5641, 0x3e98b642, 0xbe12bd06, 0xbe07bb57, 0x3f0a7b3b, 
    0xbe19cb24, 0xbf04b500, 0xbe007354, 0xbdda1cf9, 0xbdd62162, 0xbd964ce3, 0x3d56086e, 0xbd4e8056, 
    0xbd8db6fb, 0x3e156f05, 0x3ea1745e, 0x3d3f7f6d, 0xbb5ee207, 0x3ecc1c4b, 0x3e8c479b, 0x3d869b06, 
    0x3e284a05, 0xbee9a293, 0xbdfe320e, 0xbeb6401a, 0x3e7b94d9, 0x3dd1bec6, 0xbee9852e, 0xbe587bde, 
    0xbf361976, 0xbe96e5b7, 0x3ed9e84b, 0x3dea12b4, 0xbcb845e3, 0x3e6e55ac, 0x3e77c4d4, 0xbf1fb11b, 
    0x3e89f0ea, 0xbe25c952, 0xbe00d356, 0xbe4d854f, 0x3c987953, 0xbd61c85a, 0x3dbbc629, 0xbdb56369, 
    0xbcf335c5, 0x3da6dc58, 0xbdf329d9, 0x3e7ed705, 0xbce4c8bb, 0x3b83e40b, 0xbdb22ba9, 0xbe0ef0bb, 
    0x3e8355bb, 0xbda6dd40, 0xbd5d2563, 0xbcc2968e, 0xbd29b6d2, 0xbcd667ff, 0xbdb794d8, 0xbc9478c8, 
    0xbc039dd9, 0x3c297181, 0xbc99ecd0, 0xbc5fe4e0, 0xbd88cf3a, 0x3df6356d, 0xbd637456, 0xbd779d31, 
    0x3e475136, 0xbde31f14, 0x3d318356, 0xbe4a7022, 0xbd9ed3a6, 0xbd127cd6, 0x3c26ffc4, 0x3deb8b97, 
    0xbdf2e8cc, 0xbe2fd96d, 0xbd8e4fa4, 0x3e2843c3, 0xbd60be77, 0xbde4935b, 0x3e143bd8, 0x3d5fb4dc, 
    0x3dfa10fd, 0xbe386749, 0x3dd65b78, 0xbdc7373e, 0xbda71a23, 0x3dd9f6f5, 0xbdaf8b61, 0xbd8b6ebf, 
    0xbae39c5a, 0x3a396922, 0xbca2ace6, 0x3ddead45, 0xbdb0750a, 0x3d26ab0d, 0x3cb54a5e, 0x3d1f3d53, 
    0x3daf2ff6, 0xbdd5318d, 0x3cc0c591, 0x3d185c13, 0xbd91f2ec, 0x3dbb13b8, 0x3da17342, 0xbc5c0c00, 
    0x3dc99b51, 0x3dcdcddf, 0xbda2ec05, 0x3c77929b, 0xbc140dfc, 0x3e21035f, 0x3ca10ef4, 0xbe1c2854, 
    0x3cfa07d0, 0xbd6fb008, 0x3cdb9d2f, 0xbdbb5b1e, 0x3e01a0de, 0x3c9f4d73, 0xbbb6d06b, 0xbd2decc0, 
    0xbd8275f2, 0x3d939f05, 0x3d280c53, 0x3e1faa5d, 0x3d5e3f26, 0x3e084db2, 0x3dace07d, 0xbd3b87b5, 
    0xbdef865e, 0xbe4fd4d0, 0xbd448118, 0x3dc388a4, 0x3e7437ee, 0xbe22fe67, 0xbbaa2d24, 0x3e46422d, 
    0x3df9064b, 0x3e0dc4b2, 0x3be54f8b, 0x3d10ad04, 0x3cbf5360, 0x3e03f8ee, 0x3d99676c, 0xbe133523, 
    0x3df40ffc, 0xbea74810, 0x3d7a949b, 0x3d21ef4f, 0x3dbdfd54, 0x3c86af54, 0xbe39bdaa, 0xbdfa96fc, 
    0xbe36350c, 0x3e126b99, 0xbdf07531, 0xbddaa19c, 0x3db6e0f8, 0xbdee1be1, 0x3e6af6ba, 0xbe544040, 
    0x3e846abc, 0xbb2f2948, 0xbe0e4594, 0xbe813bb7, 0xba9db19c, 0xbd749dad, 0xbe7a2f81, 0x3e29188e, 
    0x3daf13fd, 0xbc432c1b, 0xbe36cdb0, 0x3e765694, 0x3d493f14, 0xbe241448, 0x3e2e5fa5, 0x3d890026, 
    0xbde27019, 0xbd0f95ba, 0x3e8a8c91, 0x3e605e9b, 0x3d85167e, 0x3d7975f1, 0x3d8c38d8, 0x3d9e14bb, 
    0xbeb3ba9d, 0x3e807fca, 0x3e532e35, 0xbce969f0, 0xbd772f95, 0x3e2984af, 0xbd931113, 0x3e840b27, 
    0x3e06e93e, 0xbd9fc9a4, 0x3d913e45, 0xbcd7e93c, 0xbdb5259b, 0x3d57ea60, 0x3d9f4a66, 0x3cf30ac8, 
    0xbdccf5ea, 0x3cf54fbe, 0x3eab1d29, 0xbd87863a, 0x3cae6b3d, 0x3dcab376, 0xbdb3cc79, 0x3e21a5c3, 
    0x3d9d7af0, 0xbe93b011, 0x3d84fb8b, 0x3e048570, 0x3e18b45c, 0xbdc41439, 0xbe88e816, 0x3e16cbf4, 
    0xbebea82a, 0x3e90151a, 0x3dcf17d8, 0xbcb00777, 0xbd8709e5, 0x3e38e131, 0xbd9322c8, 0xbdd86b77, 
    0xba3fcb23, 0x3d830ae5, 0xbdb96aae, 0x3c509a1e, 0x3e136e79, 0x3de63365, 0xbc5985bd, 0x3e014fa9, 
    0xbdf366bb, 0xbda597a1, 0x3dbdcb86, 0xbd5f80bf, 0xbc943240, 0x3de504df, 0x3dc766cb, 0x3d791359, 
    0x3e3396d3, 0xbd8b29ee, 0x3d281fe1, 0x3d04f3d6, 0x3dd56d11, 0x3de3d993, 0xbdca5889, 0xbcd9677b, 
    0xbc3ae45b, 0x3d035d90, 0x3d6c8946, 0x3e20ba17, 0x3d93b413, 0x3e20bcdf, 0x3d0a0634, 0x3d2ff51b, 
    0x3e4a04be, 0xbd86fcaa, 0x3d18179a, 0xbd28b7cb, 0xbcc0ad76, 0x3db4a9e1, 0x3cd15c35, 0x3d1ffa70, 
    0x3d243198, 0x3ddb65eb, 0xbda9b23d, 0x3dbf255b, 0x3d3c8bb9, 0xbd570bb4, 0x3dce9594, 0x3b136c75, 
    0x3d9a8b43, 0xbe74466d, 0x3d7e63f4, 0x3d0699ce, 0x3e2bcd6d, 0xba630ef5, 0xbdb9252b, 0xbd20dbc6, 
    0xbd080467, 0xbe6de19d, 0x3e2962ca, 0x3d8871b5, 0xbe52d50e, 0x3ba96e32, 0x3db1a79f, 0xbbd5a509, 
    0x3d620e56, 0xbdef6596, 0xbdde4084, 0xbc0f0736, 0x3c046e4f, 0xbd9c81cd, 0xbe6752fb, 0x3ce16bc2, 
    0xbe41442a, 0xbcdaf827, 0xbcd782ce, 0x3dc39931, 0xbe88f30f, 0xbd137751, 0xbdc63ea7, 0xbea705e3, 
    0x3c8d7f47, 0xbccccbc1, 0xbd6292af, 0xbe00920f, 0xbd1d31a0, 0xbd3a1a16, 0xbe13ef72, 0xbd6e9824, 
    0xbd1ff844, 0x3c144eb0, 0xbe0a338b, 0x3be62475, 0xbd885794, 0x3e0ee484, 0x3d1479a1, 0x3d0ff6e3, 
    0xbe5e29fe, 0x3a054d0e, 0x3e28b8b4, 0xbde1c459, 0xbdb4457b, 0xbd7e1de0, 0x3b76ab2f, 0xbd37a307, 
    0x3c0cabe5, 0x3db790b7, 0x3eb2f34b, 0xbe2c4ee4, 0x3d804701, 0xbde19f4d, 0x3d0545fb, 0x3dfe2dcd, 
    0xbde73b76, 0xbe87a97b, 0x3df7b874, 0x3ca3876b, 0xbdea726c, 0x3e2090fe, 0xbe098ecf, 0xbe04e5f5, 
    0xbe912075, 0x3e6732c7, 0x3ec26a0a, 0xbe16b2a5, 0xbdcc3303, 0x3de1969e, 0x3d81b788, 0x3da4e6dc, 
    0x3d231100, 0xbe5ee36f, 0x3c9a5fce, 0x3cc318ba, 0xbd375a30, 0xbd50cbd3, 0xbc9d08d0, 0xbe2bc2d5, 
    0xbe27f2a5, 0xbd2f2d0e, 0x3e3b9af5, 0xbe668108, 0xbe164c20, 0xbd7c7c17, 0x3e0113de, 0x3e924a20, 
    0xbe16bc51, 0x3e3a342e, 0xbd8bdd8c, 0x3e68473f, 0xbdab4c44, 0xbd0e2a23, 0x3c9bcb54, 0xbdb1af5f, 
    0xbc2906f5, 0xbd4004c4, 0x3d51f3f3, 0x3cb10e57, 0x3c190be3, 0x3d183082, 0xbdfb37ca, 0xbe0c14a4, 
    0xbccbe047, 0x3e9d289c, 0x3d6b9191, 0x3e2c9435, 0xbe4e3344, 0x3e281fdf, 0x3d3fadfd, 0xbe578118, 
    0x3e56e9fa, 0xbd45a346, 0x3d6f080a, 0xbc62fa10, 0x3dbee45f, 0xbd187e89, 0xbc70f71d, 0x3cc37a61, 
    0xbd1b376f, 0x3dee5379, 0xbcfd43a0, 0xbd2096d4, 0xbb94d2dc, 0x3e067c15, 0x3d877127, 0xbe1fd0a5, 
    0x3e788dd8, 0xbdb364f7, 0x3d6574e5, 0xbe3e69c4, 0xbd956e3e, 0xbe086868, 0xbd033656, 0x3b55856c, 
    0x3e1b858d, 0x3e30895c, 0x3e74fac6, 0x3d85dc54, 0xbc9f854a, 0xbe6cb9f8, 0x3e9f45a7, 0xbd8992a8, 
    0x3ec9de77, 0x3e83947a, 0x3de82f08, 0x3e0cab1e, 0x3d3744d3, 0xbe88fa7e, 0xbe8b5fac, 0x3ec8cb46, 
    0x3d3eb4b7, 0x3e8b4ae0, 0x3e936561, 0x3de29c15, 0x3dfa3456, 0x3de42964, 0x3f1e7316, 0xbdff8b5c, 
    0x3dc0b98f, 0x3d2676a1, 0x3b48ea2c, 0xbf039865, 0xbeb20efb, 0x3d8f2d90, 0xbcc48ef4, 0x3ef2b8df, 
    0x3e143e16, 0x3dd7e7a4, 0xbd684372, 0x3c81d4c9, 0x3da39b85, 0xbe6025a1, 0xbead0a50, 0xbe637506, 
    0xbe9cdd33, 0xbe2fa612, 0x3cbec55f, 0xbed3f295, 0xbf154d7e, 0x3dee8b24, 0x3e2cebb6, 0xbefbb673, 
    0x3d88d957, 0xbc83834b, 0xbe8376e7, 0x3ee88ca5, 0x3df4b8f7, 0xbde71773, 0xbdd1bd04, 0xbe87b5d4, 
    0x3ea9a8ce, 0x3e0bddc8, 0x3ebd6654, 0x3e38cec4, 0xbed1679f, 0x3e8927df, 0xbe0b8cc6, 0xbe6245f9, 
    0x3d919759, 0x3f08fbc0, 0x3e964bbf, 0x3ea67c05, 0x3e34ceb2, 0xbec763b2, 0x3e2f9dea, 0xbe7fef47, 
    0x3e5b82b4, 0x3da7fee6, 0x3c1a2c73, 0x3e77faa2, 0xbe9b0496, 0x3c2405e0, 0x3db9fb81, 0x3dba9259, 
    0x3c0d0408, 0x3eea1a19, 0x3ee61387, 0x3ebf702e, 0x3e5c2959, 0xbe025519, 0x3e82e34d, 0xbe0bcadb, 
    0x3f1b7b0d, 0xbdf3d514, 0xbe1538b9, 0x3df3ec6d, 0xbddd8891, 0xbe12f667, 0xbda8c800, 0x3eb48126, 
    0x3d2a90b2, 0x3d0f5f2f, 0x3d1dd739, 0xbdb48eb4, 0x3dd41d7e, 0xbd1e3124, 0x3d9a3f1c, 0x3e2b0e4d, 
    0xbd2a42b1, 0xbe0f6d13, 0x3d47f72c, 0x3dde9f3f, 0xbd54854b, 0x3e0e635f, 0x3e167bc4, 0xbb9d7592, 
    0x3e833d29, 0x3dc7001a, 0xbda71cef, 0xbd9b6d4a, 0x3dccc4cc, 0x3e5899d2, 0x3cfa5aa6, 0x3e58455f, 
    0x3de6a25a, 0x3d74310f, 0x3de99f98, 0x3c89ad86, 0xbda788b6, 0xbd99af7d, 0x3d2871b2, 0xbceef6d4, 
    0xbd424673, 0x3e11270b, 0xbcf55092, 0xbe24973c, 0xbda2a27b, 0x3cd5c384, 0xbdb55ca6, 0xbd338cb5, 
    0x3b23d83e, 0xbcd76d47, 0x3da91725, 0x3e13ebe3, 0xbdca762f, 0xbcdb4ebd, 0xbd2ad1fe, 0x3dad46a1, 
    0x3cb9ea5c, 0xbd32a0e2, 0xbddeaca3, 0xbdfe951e, 0xbc804741, 0x3d980f47, 0xbdbe85d1, 0xbd18e855, 
    0xbdc9a29f, 0x3cbf679f, 0xbc6a7e40, 0x3dd8ccf3, 0xbe20d255, 0x3e2d63a6, 0xbd600707, 0x3c0d6221, 
    0x3e392e2d, 0xbd636126, 0x3d7e6748, 0xbd721c58, 0x3aaa3245, 0x3d27227e, 0xbdf4e60b, 0x3c23a4c3, 
    0xbe62ba23, 0xbd5e2bee, 0xbdd4552e, 0x3dbe7ea2, 0x3d881fa1, 0x3df52a52, 0x3d8126cd, 0xbe6717a4, 
    0x3e685ad6, 0xbd5b8e93, 0xbdc6ba32, 0xbe28af5b, 0x3dd31093, 0x3cdd8df4, 0xbca8de3c, 0x3d7fd054, 
    0xbdb20057, 0x3c674aaa, 0xbd6e86a4, 0x3dfd079d, 0x3d9887f1, 0xbddd6a57, 0xbdc58f69, 0xbdceddde, 
    0xbeba317b, 0x3e815abd, 0x3e8ea7be, 0xbe3e4091, 0xbebf5381, 0xbd559365, 0xbd97baa0, 0xbe2283b4, 
    0xbe7eaef6, 0xbb9d042b, 0xbef9b622, 0xbd9cd0a4, 0xbe41c780, 0xbef3d384, 0xbd2341f7, 0x3ec68896, 
    0x3e91bf65, 0x3e4bc552, 0x3d139795, 0xbe903322, 0xbed329bc, 0xbe7e1525, 0xbd506da5, 0xbd98576b, 
    0x3c812e57, 0xbe1ae044, 0xbebc02ed, 0x3d4e4706, 0xbe3a8b0c, 0xbe961b7a, 0xbea8123b, 0xbe328f3b, 
    0xbe184e2c, 0xbe2fe5e8, 0x3e58c7b8, 0xbeaa595e, 0x3e62a6e0, 0xbc42e50c, 0xbede539e, 0xbeffdd24, 
    0xbdb63a3c, 0xbd900eb1, 0xbeba5394, 0x3eb0c746, 0x3e3f261e, 0x3d6c1d1d, 0xbd468803, 0xbe9d9333, 
    0xbc51f97d, 0x3d898247, 0x3e70375e, 0x3ecdee33, 0xbe290cd9, 0x3e11be55, 0x3ee1b1f8, 0xbe5c8a8d, 
    0x3c9f385b, 0x3ed538d6, 0x3da43156, 0xbbba2eac, 0x3dad1a48, 0x3e47a775, 0x3dcb7119, 0x3e84114f, 
    0xbd815a21, 0x3ebf0088, 0xbdeb9cb7, 0xbe2957f3, 0xbe270658, 0x3d717a39, 0x3ea63375, 0x3ea2209b, 
    0xbe6e7905, 0x3e119186, 0x3c80ca36, 0xbd904b3a, 0x3ebebb42, 0xbe7fffa7, 0x3eca5463, 0x3ca41da1, 
    0x3e7beee7, 0x3dc98584, 0x3e419759, 0xbd3f6466, 0xbd9f4d51, 0xbd9d6ada, 0x3e9dae77, 0x3e15c6ab, 
    0xbec2d6e7, 0xbe1fc21b, 0xbe902347, 0x3ec9c6a7, 0x3dd0ed50, 0x3e407b21, 0x3bc82d56, 0x3f1900f9, 
    0xbdb26495, 0xbdc976fa, 0xbe09b885, 0xbe1c5e71, 0xbe4bca6f, 0xbe26ebfd, 0xbcd8fb4e, 0x3e2cab02, 
    0x3e1f0a4d, 0x3d20e16d, 0xbef4d0d5, 0x3dd01d91, 0x3d8943b6, 0xbe9ebeea, 0xbd00644a, 0x3d3359ac, 
    0x3e679232, 0xbe9c9796, 0xbe467d29, 0xbd28bad1, 0xbdb5058f, 0x3e4ad1b0, 0xbe4bdc91, 0xbdd9bc96, 
    0xbebadc26, 0xbeb087da, 0xbe7a7ca2, 0xbe00bd51, 0x3eb79ff3, 0x3e1938ef, 0xbdc07397, 0xbdb968db, 
    0x3e80e2d3, 0xbe7798f8, 0x3d6e8dde, 0xbee1f3f4, 0xbe4a9255, 0x3c7d115d, 0xbe81d91c, 0x3d270ca4, 
    0x3dcbdc20, 0xbdc52324, 0xbeefb279, 0xbe1a74ac, 0x3e9aeccb, 0xbeb8c1de, 0xbe80a9fd, 0xbe9db395, 
    0xffffe06a, 0x00000004, 0x00001e00, 0x3cefac1c, 0xbc19f82e, 0x3cb4ff6a, 0xbc3b9f39, 0x3c8287e4, 
    0x3d69de4a, 0xbcec1456, 0xbd45de84, 0x3cf3df71, 0x3d05422d, 0x3d231f20, 0x3cfebba6, 0x3d1daf0a, 
    0x3cb03bc7, 0x3c929051, 0xbcb52047, 0xbcb87b36, 0x3da06615, 0x3d6dc5f7, 0x3da2a93b, 0x3db9c3b2, 
    0x3cb4d9c4, 0x3d46c183, 0x3dca1a8f, 0x3d5f7375, 0x3d00def2, 0xbce5b748, 0xba1885b9, 0xbd3cc17d, 
    0xbd4f5023, 0x3ce56525, 0x3d1159c0, 0x3c7f8cdf, 0x3ca7708f, 0x3d8bd464, 0x3c79085c, 0xbcdf721f, 
    0xbd0c9331, 0xbd655014, 0xbdee936d, 0x3d8b0327, 0x3ad85cc0, 0xbd0c3fc2, 0x3cabb19a, 0x3c2a74a9, 
    0x3ca76299, 0x3bc6f9dc, 0x3c18ac19, 0xbcd53405, 0x3d0cb51d, 0xbd1911b9, 0xbce5d8b9, 0xbcdf067c, 
    0xbc8983fa, 0x3cfc56da, 0xbc06f228, 0xbd474a80, 0x3d7aad82, 0x3d17e038, 0x3d57852f, 0x3cb1b007, 
    0x3d63c499, 0x3c47f978, 0x3dde376b, 0x3d008a27, 0x3c4a75fd, 0xbbd59ef8, 0x3ccfcee9, 0xbcc26738, 
    0xbd126701, 0xbd0386b2, 0x3cc49a00, 0xbd199270, 0xbce6dc1a, 0x3d41f41c, 0x3d11b852, 0xbc77c9a2, 
    0x3bc2a5fb, 0xbdcb8df4, 0xbe109a51, 0x3d3d207d, 0xbcba5f46, 0xbd64ef1b, 0xba68996d, 0x3d01c1e4, 
    0x3d10c798, 0x3d12602b, 0xbd77e87d, 0xbd10d68b, 0xbccd11d3, 0x3ce3b6d3, 0x3d033876, 0x3c1f17f5, 
    0x3d0f9df1, 0xbb7a5012, 0x3cd05254, 0x3d34f080, 0x3c556434, 0x3d1319c6, 0xbb965e83, 0x3dcc4faf, 
    0x3dd8d46d, 0x3d668d26, 0x3df58116, 0x3dd5ad2c, 0x3d6d27d9, 0xbd5a95a7, 0x3cfc80e1, 0xbd1c83a5, 
    0xbd3a605f, 0xba497f80, 0x3d4ec516, 0x3cd4790d, 0x3d5de1f1, 0x3d9ee33e, 0x3d90f241, 0x3d71077e, 
    0xbd115ee5, 0xbd853806, 0xbe1361a6, 0x3d0a122c, 0xbd104a9a, 0xbbdacd18, 0x3d474ca7, 0x3ccbd117, 
    0x3d20b783, 0xbb727a46, 0x3e10610a, 0x3d543e7c, 0x3d910abe, 0xbbd58c1c, 0x3d866629, 0x3d07a558, 
    0xbcff13ff, 0xbd36bf73, 0xbd21c719, 0x3ca1d39c, 0x3d8b3d57, 0xbcf534d8, 0xbccf34c7, 0x3d0d837a, 
    0xbc69d6e6, 0xbd1e0eaa, 0xbd3254be, 0xbdc55dd0, 0xbda4d951, 0xbd0f6ae5, 0xbdf24d2f, 0xbd104405, 
    0xbd7a6fda, 0xbd021681, 0xbd99152f, 0x3d56990d, 0xbd00bcbb, 0xbc174878, 0xbdcdb4b8, 0xb8a3ac70, 
    0x3cdfe452, 0x3d1bb303, 0x3d1c1617, 0xbc99bc3b, 0xbdf53d35, 0xbd8ec431, 0xbd5771e8, 0x3d904d95, 
    0xbcff1e4e, 0xbcc980b9, 0x3e23f2e4, 0x3d8cabfa, 0x3daca65c, 0x3cbe1ffc, 0x3d3aab11, 0x3de28076, 
    0x3a58579a, 0xbe07823d, 0xbd960ecc, 0xba4eeae2, 0x3cad11ce, 0xbcc56ff8, 0xbd2d5369, 0xbde64c4a, 
    0xbdb93882, 0xbe005d98, 0xbdec6234, 0xbddf5ccf, 0xbacce966, 0xbe27638c, 0xbd4be7b3, 0xbe079e5d, 
    0xbe01721b, 0xbd5ff0d0, 0xb9eec570, 0xbd75f9ab, 0xbdea0583, 0xbd3765cc, 0x3d2e3f59, 0xbd190b22, 
    0x3c250d40, 0xbd05e462, 0xbca9e8c0, 0x3de0a29b, 0xbe06440b, 0xbd51b305, 0xbde5524b, 0xbc3ce3d1, 
    0x3d8c3341, 0x3dd54ebb, 0x3e32e0a0, 0x3c9b16a6, 0x3d670006, 0xbd044021, 0x3dc359f4, 0x3d07a99b, 
    0x3d08abf1, 0xbafc1483, 0xbd0a5b12, 0x3da5bc2b, 0x3d5159ab, 0x3c271aa2, 0x3d37f17c, 0x3cb63774, 
    0xbc90f956, 0xbd0323a0, 0xbe04c8af, 0xbdc09712, 0xbd886063, 0xbd2de32a, 0xbdf4334d, 0xbe3249af, 
    0xbca43073, 0xbdae409b, 0xbd66f299, 0xbd9cda40, 0xbb658fd4, 0x3c58e22b, 0x3c568d75, 0xbb990d13, 
    0x3c249142, 0x3caa516f, 0xbd2e2b89, 0x3cbe4907, 0x3d5f6864, 0x3c79c65c, 0x3d5f3e69, 0x3b1dc25a, 
    0xba052c3d, 0x3cf10345, 0x3cfae51e, 0x3bd11df2, 0x3c5b8cd7, 0x3b0cbf82, 0x3cdae708, 0x3d0a217e, 
    0x3cc4a7c7, 0x3b9a4964, 0x3d5448d9, 0x3b99189e, 0xba892cff, 0x3b22539c, 0xbbd38d22, 0xbd5155fd, 
    0xbaff89b1, 0xbc93326a, 0x3cc4f9a5, 0x3b806f1a, 0xbc239c15, 0x3ca14522, 0x3d20ccc6, 0x3d36c247, 
    0x3c0125f0, 0xbc06d0a8, 0x3b5d9585, 0xbd00ca54, 0xbce823c4, 0xbc5255af, 0xbb9ffcb8, 0xbd08878d, 
    0x3b36d610, 0x3c506db4, 0x3d879678, 0x3d037924, 0x3cac876d, 0x3d540f4e, 0x3d187794, 0x386f61b9, 
    0x3b87e0f7, 0x3cc68561, 0x3c8342df, 0x3bde986a, 0xbb2c556c, 0x3c16e865, 0x3d14f71c, 0x3b9a6cd8, 
    0x3ca8ce88, 0x3d235513, 0x3c53f58d, 0x3c42bd0e, 0x3abf8861, 0x3c83bc97, 0xbb5d3519, 0x3c340be9, 
    0xbc194a26, 0x3c1ae27f, 0x3c36f08d, 0x3cbaa21f, 0x3c4fa62d, 0x3d12b28e, 0x3c4f36ae, 0x3d1d87e1, 
    0xbbec1edb, 0x3ba6f784, 0xbc0d55e6, 0xbbe88cba, 0xbd157d34, 0xbbc9fe7b, 0x3b276426, 0x3cd34b8e, 
    0xbbfebe24, 0x3d72d537, 0x3db6d8ad, 0x3c30b6c8, 0x3c94cb79, 0x3ce57731, 0x3c6e6735, 0x3bbdad8e, 
    0xbb36961b, 0x3d3541dc, 0x3b2955f5, 0x3d2b92df, 0x3cdef3ab, 0x3ccaa0a0, 0x3c52c4d9, 0x3cccba2e, 
    0x3cf6ec23, 0x3c2f2914, 0x3d190633, 0x3d2384ab, 0x3a95940b, 0x3cbc7f09, 0xbc7a9a11, 0xbc40a560, 
    0xbce8a7b6, 0x3c6f4bd7, 0x3cf0d2c5, 0x3cf18c2a, 0x3d4e1e44, 0x3d4691d4, 0x3d84747c, 0x3d19c9eb, 
    0x3abde9cc, 0x3d0c5e65, 0x3c2b06c4, 0xbcadc44f, 0xbd16823c, 0xbc817ef4, 0xbcb95dca, 0x3cc0505f, 
    0x3ca9520e, 0x3c876564, 0x3d327b67, 0x3d8f452f, 0xbb05beff, 0xbce8014b, 0x3d5fda1f, 0x3daa3272, 
    0x3d35d2f4, 0xbd800966, 0x3d0d5fb0, 0x3c31476d, 0x3cedc290, 0x3da41e80, 0x3bba5858, 0x3c8e5e78, 
    0xbd1d533f, 0xbd432d8e, 0xbc9718fe, 0x3d2f69da, 0xbcefc8e7, 0xbd5549ca, 0x3d44afdd, 0x3ccd1b56, 
    0x3ad04e72, 0xbd998238, 0xbde80a9c, 0xbd6d994c, 0xbdc0e4c1, 0xbaa5e568, 0xbd64ee03, 0xba816621, 
    0xbd0e8e1d, 0xbd82c8c3, 0xbb4ac11a, 0x3d51e0ed, 0x3baebb01, 0xbdbb2fac, 0xbcb7f9e8, 0x39abaa8b, 
    0x3a9e1784, 0xbca07d08, 0x3db0e4f8, 0xbc85add9, 0xbb1c7e95, 0xbc4774fc, 0x3ce9b6c8, 0x3d22dbd2, 
    0x3d0606d5, 0xbd034a12, 0x3d48cf5f, 0x3d010a26, 0xbd4cf792, 0x3d5042af, 0xbd1edacb, 0x3d36440c, 
    0x3c98540b, 0xbd230c28, 0xbafc2f4d, 0xbcb82ab2, 0x3baff251, 0xbce58893, 0xbc677df3, 0xbd6be7ff, 
    0xbdab5544, 0xbd2bf74a, 0xbcd3aba8, 0xbddd4665, 0xbd5a0b3e, 0xbcf31878, 0xbcba97b6, 0xbd900abc, 
    0xbd9212bf, 0x3cfab5ec, 0xbdad2797, 0xbd46ef06, 0xbd996816, 0x3cb3214c, 0xbc881efa, 0x3d821c0f, 
    0xbd1c0ecf, 0x3d1fdd22, 0x3d82d80a, 0x3c8c2bdc, 0xbc6e2e7a, 0x3d651b3f, 0x3d2e524c, 0x3d345ad4, 
    0x3da493de, 0xbcbeafb6, 0x3c1ff7f8, 0x3ae41c8f, 0xbd290f16, 0x3d25683c, 0x3d8e1f1f, 0x3c7f5013, 
    0xbbe50457, 0xbcf8196e, 0xbd5aee22, 0xbd435845, 0xbdb0c588, 0xbcae72cd, 0xbd732203, 0x3d1fb866, 
    0xbc4d1eb8, 0xbd9592f8, 0xbdb8f800, 0xbdd44f0b, 0xbd1cf9ee, 0xbdac1ff0, 0xbcc59ac7, 0x3be430b8, 
    0xbda3f639, 0x3d0dc91a, 0xbcdc1cba, 0x3d47e4fd, 0xbdb02e54, 0xbcdb2510, 0xbd01c906, 0xbd8f8cff, 
    0xbcc6c91a, 0xbbbecad6, 0x3c4b5bf5, 0x3ca4edbd, 0x3d4d21dd, 0xbbf44ce8, 0xbc5d595e, 0xbce1d711, 
    0xbb6cd5ad, 0x3c156ae6, 0x3cbb8fae, 0x3ceba437, 0x3d460db0, 0x3bf89fbc, 0x3d0f0070, 0xbccc57b5, 
    0x3d1ad452, 0x3d05ce56, 0xbd06b430, 0x3d501a8e, 0x3c11deed, 0x3c80528b, 0x3d5421ca, 0xbca058d7, 
    0xbba1691d, 0x3d039239, 0x3ce371a0, 0x3ccdb3f5, 0x3d220f31, 0xbcfa0621, 0x3d1eafa1, 0x3cee79de, 
    0xba240975, 0xbafdd216, 0x3c6798cb, 0xbcf686b1, 0xbcbbc683, 0x3d4b06d1, 0x3d646102, 0x3c9fc473, 
    0xbc088886, 0x3d33b88c, 0x3c6254f6, 0x3d1f1103, 0xbc1872d6, 0x3ce4be86, 0x3cd9d3ec, 0xba753a3b, 
    0xbd0a293b, 0x3cc36252, 0xbbae505d, 0x3cc80532, 0x3d39d0c5, 0xbb80562c, 0x3c3326b7, 0x3cbb8997, 
    0xbc652aed, 0xbd0a7506, 0xbc0f63b3, 0xbcc04dfa, 0xbcc126a5, 0x3c5fbc80, 0xbc57fbba, 0x3cc74adb, 
    0x3ce7b56c, 0x3d31c0b0, 0x3d4b1044, 0x3d0724ae, 0xbc04c1a1, 0xbd16b4bf, 0xbd104aa1, 0xbc89900e, 
    0xbcc57002, 0x3cfdf9f6, 0xbc64f5ee, 0x3b9c23ed, 0x3c92d920, 0x3cbbbeb6, 0x3b1d0111, 0x3cc63d53, 
    0x3c28c8bd, 0xbcdba9c5, 0x3cc4f74f, 0x3d3c6a8b, 0x3be1d6ab, 0x3cd966e0, 0x3d48a91e, 0x3d0748bd, 
    0x3cc83460, 0x3d0a4511, 0x3a582dcd, 0xbc5b82d2, 0x3d10d44f, 0xbc53b0e3, 0x3cfe0767, 0x3ca67c9d, 
    0x3c0159fa, 0xbc2e16c0, 0xbbe1c0ea, 0x3bf55852, 0x3bb5d564, 0x3d591b4e, 0x3be2c3e3, 0x3b86f0c8, 
    0x3c78ffb8, 0x3d344073, 0x3ccd43a8, 0x3be1f7aa, 0x3bccb5fd, 0x3cf03e8a, 0x3c3d0678, 0x3ca86cad, 
    0xbccf0252, 0x3d10f92d, 0xbcec79a1, 0x3d0cbc8c, 0x3c7e0474, 0xbb0fd79f, 0xbbae8f38, 0xbca5d5b7, 
    0x3c4aca83, 0x3c8c2f6b, 0xbb817220, 0xb9fddda4, 0xbd11c325, 0x3cd3c582, 0xbca0782b, 0xba5a45d7, 
    0x3bd5e661, 0x3d08589d, 0x3cdcc97d, 0xb9ae4054, 0x3cae84fb, 0x3d405caa, 0x3d0f2cb0, 0x3d1b4b9c, 
    0x3ba44db0, 0x3d84d458, 0x3d01c846, 0x3d12dc30, 0x3c7a2018, 0x3c918e39, 0x3cbd132d, 0x3d6a56bb, 
    0x3d7f7003, 0x3c8db11d, 0x3c5c11ca, 0x3d81a42e, 0xbb53e85f, 0x3d6fdbcf, 0x3d6a98c9, 0x3c40f9fb, 
    0x3d54a491, 0x3cffc554, 0x3ca7c4b1, 0x3d123e3c, 0xbc1a34ad, 0xbc513090, 0x3c9216f2, 0x3bd16301, 
    0x3bdeffc0, 0xbd14e81d, 0x3c4bdd6a, 0xbd458a96, 0xbd43afed, 0x3d13e060, 0xbcda54d1, 0x3c95e997, 
    0xbc86aacf, 0x3cc8a247, 0xbc10d47f, 0xbb209e4d, 0xbc69fe27, 0x3d26d39f, 0x3d2f32c9, 0x3d542dc6, 
    0x3d1b39c5, 0xbb461bc2, 0xbcd241e2, 0x3c9a578b, 0xbc9d6589, 0xbcb6543f, 0xbc69d86a, 0xbbd3c84f, 
    0x3ca2d0cf, 0x3d2a0085, 0xbcb74dc7, 0xbcc3943d, 0x3c928832, 0x3d0426af, 0x3c0e930f, 0xbd14c4ce, 
    0xbc27e299, 0x3c93670a, 0xbd16cd76, 0xbce84700, 0xbcf93034, 0xbcd34348, 0x3ce67187, 0x3c77643b, 
    0x3d27045c, 0x3d21c4ca, 0xbd1f0c22, 0xbd03215a, 0x3c76ce49, 0xba8a5d28, 0x3cd7bfcb, 0xbc9c193a, 
    0xbce16e5b, 0x3d3144be, 0xbd02893f, 0x3cddbe04, 0x3d016f27, 0xbb26c97d, 0x3d1aaccb, 0xbc81cb1d, 
    0x3c56ad8e, 0x3d3a68a1, 0x3d1f217f, 0xbcc09a54, 0x3cf05854, 0x3cb1103d, 0xbc9b4ea3, 0x3cf6a6f4, 
    0x3d5e74d8, 0x39c9e550, 0x3d13a34c, 0x3ccf4a7f, 0xbd04c5bd, 0x3d094d36, 0x3b8e6e69, 0xbce5824e, 
    0xbc1dd2ef, 0x3d5697bc, 0x3c8e3a28, 0xbcd4a55a, 0x3c791224, 0x3c9effcd, 0xbcfb601f, 0x39eda172, 
    0xbc94cc4f, 0xbbe2cd9e, 0xbd049139, 0xbdf5122f, 0xbdf9fa95, 0x3d6082f9, 0xbd776cac, 0xbc613b72, 
    0xbe8fe247, 0xbe337dbe, 0xbd67f4f1, 0xbd986dc2, 0xbde5cefa, 0xbe096fd0, 0x3de79a4a, 0x3e00b55d, 
    0xbdc05352, 0xbd84c739, 0xbd2f1434, 0x3dde8094, 0x3dabe9c9, 0x3c26155c, 0x3dc5d168, 0xbd429e7b, 
    0x3dd7933d, 0x3d205ae2, 0x3cf4286b, 0x3c202e5a, 0xbdd76adf, 0x3d287f55, 0xbe108c2f, 0xbd6cbd42, 
    0x3c31a0c5, 0xbbd99518, 0x3dae5706, 0x3e0a9b51, 0xbb5bd3d8, 0x3c5e0976, 0xbd87e132, 0xbd8ae0bd, 
    0x3e1ab187, 0x3dfbe5cc, 0x3cf9ac85, 0xbd20f723, 0xbdb0ad14, 0x3c6ff5f4, 0x3db41bd0, 0xbdae3499, 
    0xbda9d801, 0xbe8c881e, 0xbe675883, 0xbe10a441, 0xbdc501f4, 0x3cba29c1, 0x3d9eadf5, 0x3c092ff1, 
    0xbd88ba35, 0x3d94b5c9, 0x3d9d1276, 0x3ad2df32, 0xbc9ce6d0, 0x3c21bbdd, 0x3de4ceb1, 0xbde03f9e, 
    0xbd9b0ab6, 0x3df610a2, 0xbdc96091, 0xbdce0229, 0xbd7aa2a3, 0x3d09540c, 0xbe138454, 0xbdd10150, 
    0xbc3261e9, 0x3d835b22, 0x3bfd5cb2, 0x3e14dd2e, 0x3d055955, 0xbe25a042, 0xbd27acdb, 0xbcf4350f, 
    0x3c666f09, 0xbd81dce4, 0x3cdb998b, 0x3c435d94, 0xbdace387, 0xbe110676, 0xbd69c91b, 0xbd15106c, 
    0xbe5d8d55, 0xbe217082, 0xbd038816, 0xbde61c55, 0xbe0de495, 0xbdae8a49, 0xbc52be2b, 0x3d10c660, 
    0x3cfcc599, 0x3dcc804e, 0x3ce98f4c, 0x3e0e34b3, 0xbdad0c2d, 0x3b78145f, 0x3da86c6b, 0xbcad7c7b, 
    0xbd3e0518, 0x3d976ab2, 0xbb8ce557, 0x3cb4cd35, 0x3d6f7cea, 0x3d2f8891, 0xbdc065d9, 0xbd4bf54c, 
    0x3e0ecb41, 0x3d18b2c4, 0xbba5b11e, 0xbb0072f9, 0x3d9762d2, 0xbd2f9cb7, 0xbd887ef1, 0x3dbe7e18, 
    0x3e1ab4d4, 0xbd433f30, 0x3de7c621, 0x3dc19171, 0xbd225365, 0xbd3f7660, 0x3d9a043f, 0x3dde2460, 
    0x3d191ceb, 0xbd100048, 0x3d0c5047, 0x3b172f40, 0x3d78de69, 0x3d5e32ed, 0xbc937adc, 0x3d60b18c, 
    0xbd530d70, 0xbd423e00, 0x3d98739f, 0x3ba3c984, 0x3d8f6b28, 0x3c1b4d8d, 0xbd010681, 0xbc85b05f, 
    0x3c8f233c, 0x3d3a4c43, 0x3d3255d6, 0x3d3737ac, 0x3d10cfc0, 0xbd1f45a1, 0xbc0f3ec3, 0xbcc0f4e7, 
    0x3c3543a8, 0xbd322e35, 0x3ce4f90a, 0xbd1530b6, 0xbd768091, 0xbd8db7dc, 0xbd1598d9, 0xbcb8ccab, 
    0xbd0e6ea9, 0xbd302f88, 0xbda06927, 0x3b82ad2f, 0xbbcc31c9, 0xbd2a1ae9, 0x3da84286, 0xbbb309fb, 
    0x3d0dc034, 0xbbe7b515, 0x3d514a1d, 0x3d3d4366, 0xbd42bd8a, 0xbd28aab9, 0xbd29da31, 0xbd9edc94, 
    0x3d81e191, 0xbcc9881b, 0x3d698471, 0x3cab2710, 0x3d9201a6, 0x3b4453ef, 0xbcc864b5, 0x3d90a7d6, 
    0xbcfcf1e8, 0xbcf01f4f, 0xbd3af969, 0x3c34e9fe, 0x3da6859e, 0xb9c93ae5, 0x3d612825, 0x3d14333c, 
    0x3cdecc6e, 0xbcb6e10c, 0x3d59477c, 0x3d977fdc, 0xbcc8f6ca, 0xbc010705, 0x3c8e5fba, 0x3d7c10be, 
    0x3ca869fd, 0xbd9d4dd3, 0xbd4d03b3, 0xbd579f92, 0x3a95a2ee, 0x3d18fa81, 0x3d91b547, 0xbc2bee3b, 
    0xbd7f5c89, 0xbca4e8ee, 0xbc94e5f3, 0xbd88bed7, 0x3ce50039, 0x3d474302, 0x3d8125ae, 0xbbd0cc12, 
    0x3d418a24, 0xbb492ef3, 0x3d00384b, 0x3d029b56, 0x3b026b26, 0x3c686f65, 0xbb94a53f, 0x3d838b79, 
    0x3dc76ea6, 0x3de1dbcb, 0x3dab03ca, 0xbc84d84a, 0x3d586116, 0xbb0053ef, 0x37dc2bab, 0x3cf44948, 
    0x3c83e483, 0x3c2d5d49, 0x3da6596d, 0x3daaaf8a, 0x3d6a19a0, 0xbd1de293, 0x3da899b3, 0xbb1e319d, 
    0xbd337441, 0x3d778c94, 0xbd99cbb6, 0xbc17e5be, 0xbce028f0, 0xbc3b1945, 0x3d378db3, 0x3cf3b8a9, 
    0x3d2ce4ce, 0x3d120ad0, 0x3d474e7c, 0xbbef6674, 0xbcfcf5b0, 0xbd38c033, 0x3d186902, 0x3d435741, 
    0xbc1c64f2, 0xbdf42255, 0xbe077321, 0xbd5810d1, 0xbd59c97e, 0xbd131f56, 0x3d17ea84, 0xbd3554da, 
    0xbad530be, 0xbddc8374, 0xbdf0db47, 0xbded9969, 0xbd290b8d, 0xbda3d7fd, 0xbd8ac87e, 0xbddba5a7, 
    0xbd7f049f, 0x3d31a686, 0xbccf0f69, 0xbd185a80, 0xbd4b8312, 0xbcd8d4ec, 0x3b41f1c4, 0xbc7adbc3, 
    0x3d6e6dab, 0x3d87006a, 0x3d023c2c, 0x3cf2957e, 0xbd9fc4d9, 0xbd4a0e2b, 0x3c4335fe, 0x3d3969d7, 
    0xbbdca12d, 0x3db7283a, 0x3dbc1b14, 0x3d8b9324, 0x3d39eecc, 0x3c811e8c, 0xbc83c658, 0xbb3bf5cc, 
    0xb927c65a, 0xbdcc97f3, 0xbdc9f912, 0xbd7338dd, 0xbcc102cb, 0xbbb4fed4, 0xbd6254d2, 0x3d14f3d3, 
    0x3c2eed77, 0xbe0732f3, 0xbe22fb15, 0xbdbeda1e, 0xbd9026ba, 0xbd0c70e8, 0xbcb92018, 0xbd38f665, 
    0xbd82bd18, 0xbca35d89, 0x3ce42cb5, 0x3c8b56fb, 0xbcf3f2f4, 0xbd7f9371, 0xbd12f5fe, 0xbd73e8b1, 
    0xbcbf269c, 0xbc3f9282, 0x3d6e6920, 0x3d4d9cb1, 0x3c2b0f91, 0xbca18780, 0xbd55929a, 0xbb1f164b, 
    0x3d5265b6, 0x3c1d8ff1, 0x3dafbfdb, 0x3d81aed4, 0x3d2f5d91, 0xbce22e89, 0xbc40203c, 0xbc795420, 
    0xbd20ccc6, 0xbdea1c81, 0xbdf00911, 0xbcd86eaa, 0xbc0c39e1, 0xbd16d193, 0xbd0a521c, 0x3cdeef8c, 
    0x3cd20f4d, 0xbd167645, 0xbdc9c5bc, 0xbde77ac1, 0x3bb87b9f, 0xbdc5f437, 0xbcccc559, 0xbc6ea8db, 
    0x3ce1a7c0, 0x3cea07a3, 0xbd1b7177, 0x3d1e8e13, 0xbcd98aca, 0xbbfbd516, 0x3c7a5f99, 0xba9f6edf, 
    0x3d8b10a3, 0x3cb9ecd0, 0xbce565c8, 0xbd84bdf0, 0x3d93c629, 0x3d4e775d, 0x3d7e0ef9, 0xbd672ddb, 
    0xbe020016, 0xbdf31b1c, 0x3cd0cad5, 0xbdc4639e, 0xbdabd06d, 0x3d8b1852, 0x3cf782de, 0x3c8244dd, 
    0x3d41148b, 0x3cfdc195, 0x3c7c7ec1, 0x3d80e9f3, 0x3c90f97e, 0xbc8fac6a, 0xbd96ec15, 0x3b13bc3d, 
    0x3ba6c507, 0x3d725958, 0xbda11887, 0xbd92e9c9, 0xbd5c7bca, 0x3d496fe4, 0xbd85a7e4, 0x3d72b312, 
    0xbda79783, 0x3cddaeac, 0x3bad5d52, 0x3cb3440c, 0x3c3edafc, 0xbceeeab1, 0xbccda1fd, 0xb9b0b385, 
    0x3d5c12fd, 0xbd556f62, 0x3d8748e3, 0xbd9be93b, 0x3d96f919, 0x3d5e37c8, 0x3d7fdd3b, 0xbcbcd85a, 
    0xbd54d1c1, 0x3c40aad4, 0xbdd61cce, 0xbcb7bcc2, 0x3d1ee6f4, 0xbc80dac5, 0x3d5f19e7, 0xbccf4a16, 
    0x3be8fd33, 0xbc80ed01, 0x3d0419ca, 0xbcddb612, 0x3d038f6e, 0xbd416f65, 0xbdc36998, 0xbc17f927, 
    0xbda6954a, 0xbccf416f, 0xbd1c5969, 0xbccbf487, 0xbd989615, 0xbc644825, 0xbd58ea06, 0xbce2e011, 
    0x3c33137d, 0xbde94099, 0x3d87761c, 0xbc5c9be3, 0xbd1be937, 0x3b43583c, 0xbd812bb5, 0xbd9f6a57, 
    0xbcddb59b, 0x3d731873, 0x3dfc56c8, 0x3d4ea00c, 0x3d605624, 0x3db5a563, 0x3c0f7b39, 0x3ccca523, 
    0xbd3d6b60, 0xbd1cae43, 0x3cbe4c42, 0xbd3e6a44, 0xbdb58bc2, 0x3c9f6258, 0xbd1d57f7, 0xbd746949, 
    0x3bb1fe30, 0x3d3819f5, 0x3de8e274, 0xbd3e054f, 0xbdacf20f, 0xbdc1152d, 0xbdc63211, 0xbd14782a, 
    0xbc120cfb, 0xbb9fef5c, 0xbd966aac, 0xbd3deb49, 0xbcb41cdd, 0x3d5c2058, 0x3c8e872d, 0x39ea99e5, 
    0xbd82a4ec, 0xbc79ed32, 0xbc4bf59b, 0xbddb78bf, 0x3bd5b239, 0xbcfae907, 0xbe04b3be, 0xbc0995c4, 
    0xbd5b4599, 0xbcea61ce, 0x3d6ea9d0, 0xbe82cab4, 0x3e35b1bc, 0x3e9891bd, 0x3e07a79f, 0xbe057f0a, 
    0xbbff5565, 0x3dcfed26, 0xbe2658cf, 0x3da772fe, 0xbd4ddd3e, 0xbdbccdf7, 0xbcc160a8, 0xbdc530ca, 
    0xbe0e8a23, 0x3de0ca23, 0x3e198040, 0x3e1cd4e5, 0xbda44326, 0xbd8d85c0, 0xbe50af7d, 0xbe8d9932, 
    0x3cd125b5, 0xbcb6d576, 0x3c818696, 0x3d4f8c0c, 0x3ddba48c, 0xbd9089eb, 0x3db08c96, 0xbd0ebd7b, 
    0xbd88988a, 0x3d9ccc73, 0xbdfceffa, 0xbe46ed4b, 0xbdc6ac2c, 0xbd78c7af, 0x3cd903ec, 0xbd42da43, 
    0x3dda7b87, 0x3deef8ec, 0x3ef77a62, 0x3ca880f3, 0x3e3aac49, 0x3e978832, 0x3e3d8c45, 0x3e198b24, 
    0xbda65f97, 0xbdc238dd, 0x3d7d79b2, 0xbd1a1406, 0xbe114428, 0x3e03a10c, 0x3dfeb449, 0x3ba8bf25, 
    0x3d058e80, 0x3cbc24b5, 0x3d602796, 0x3dae3436, 0xbcc1d3fe, 0xbdcb8bbf, 0xbe077360, 0xbe1a1fa8, 
    0x3cc88e16, 0xbe32f7f9, 0x3e1bb9d0, 0xbdacc8d6, 0xbdb88ce2, 0x3e2db16f, 0xbd1e677c, 0x3d8430b1, 
    0x3da73427, 0xbca962e5, 0xbd0f6b56, 0xbdb06ebf, 0xbe65b767, 0x3c3a7588, 0xbdce3ef7, 0x3c9e4d2a, 
    0x3d8e36c5, 0x3b69f9ba, 0x3ea44d70, 0x3c64b594, 0x3ec09841, 0x3dc8e1d2, 0x3e055cce, 0x3ddc0116, 
    0xbe04c218, 0xbd0d882d, 0xbe362dec, 0x3dee3945, 0x3d4f01f5, 0xbe24b001, 0x3e1cf5c8, 0xbdd164c9, 
    0x3cd0ee0f, 0x3d256e57, 0x3e31cded, 0xbd977bd3, 0x3d8807db, 0x3dbcbe68, 0x3d25c601, 0xbdc65189, 
    0xbe4f04fe, 0x3d41f8d9, 0x3cdceb71, 0xbb3c288e, 0xbd26d850, 0x3e32f138, 0xbcaa6426, 0x3e201ca3, 
    0xbcf0cf2d, 0x3d27aa43, 0xbe6cba1e, 0xbdbc0765, 0xbddcf7ca, 0xbe379485, 0xbdec494d, 0x3e0722c4, 
    0xbd98c08f, 0x3d907482, 0x3eebff2f, 0x3c9a9662, 0xbbcce81c, 0xbcc04ec9, 0xbcd40dbd, 0x3bf62365, 
    0x3c835127, 0x3ccffc27, 0xbd289517, 0xbbd36de6, 0xbc7fd808, 0x3c8c18a0, 0x3cb9befe, 0xbc88610e, 
    0x3a5556e3, 0xbb63e1ac, 0x3adb0d96, 0xbced25ef, 0x3d215070, 0x3d80ef27, 0x3d068963, 0x3a19f790, 
    0x3d5a8645, 0x3d9be7e0, 0x3ca15cf2, 0x3da7eff8, 0x3d6c082a, 0xbc8ead21, 0xbac2bc05, 0x3c48ffa0, 
    0xbc82cfab, 0xb862cb44, 0x3d1c3455, 0x3d19d9a2, 0x3d2a4e65, 0x3d5d357e, 0x3d470a32, 0x3cb7c292, 
    0xbd340fe3, 0xbd85a2e9, 0xbde4fffe, 0x3c332ee6, 0xbca7cd29, 0x3ca33821, 0xbd09848d, 0x3c832705, 
    0x3d0b2cec, 0xbd392d10, 0x3cbcd906, 0xbcec1271, 0x3ccd32cd, 0xbcc05594, 0x3c8b80cb, 0x3d23811e, 
    0x3d325abe, 0x3c227256, 0xbbce3b94, 0x3cdbe46b, 0x3d7b20bf, 0xbb7d87cc, 0x3d465822, 0x3d9a541a, 
    0x3dbcbc26, 0x3d5d392d, 0x3d38b4de, 0x3db1de58, 0x3d5c2695, 0x3b639d9a, 0x3c09b46c, 0xbd3b3081, 
    0xbcf6140e, 0xbc75016a, 0x3cc40cb2, 0xbc72aa24, 0x3d12d335, 0x3d26855e, 0xbc6339bf, 0x3d1b1220, 
    0x3c521eb6, 0xbd8b8e58, 0xbdbaa18c, 0x3dab6d7e, 0x3d070724, 0x3c8c2a91, 0xbd295b0c, 0x3d2a0a59, 
    0x3d3a3852, 0xbca0a3ae, 0xbc4047f1, 0xbc54061d, 0x3cd2057c, 0xbc3bfe62, 0xbc194b9d, 0xbd02073c, 
    0x3d25ff6e, 0xbc5b3a06, 0x3c83f267, 0x3c35d7b8, 0x3c39d9ea, 0x3d8e853b, 0x3da63432, 0x3d3cf854, 
    0x3d31d5e4, 0x3d8385e2, 0x3d5bc34e, 0x3d4b8775, 0x3d5798d1, 0x3cc71eeb, 0x3cd17442, 0xbbc84e27, 
    0x3b8e14fe, 0x3d03e0a5, 0xbca9b4af, 0xbc7bfbcf, 0x3c13d522, 0x3d4400a7, 0x3d65adf3, 0x3d1e2acf, 
    0xbc9fb06b, 0xbd8ce1ca, 0xbdfb0062, 0xbd88fe34, 0xbd88be29, 0xbd5f9268, 0xbdb062f3, 0xbd8402e4, 
    0xbd818b8b, 0xbbc079b4, 0xbcad1455, 0xbd379af4, 0x3d5d43bd, 0xbd54b403, 0xbd9594fd, 0x3d5428bb, 
    0xbd8f0623, 0xbd988141, 0xbc85812a, 0xbd81f831, 0x3d7b46da, 0x3c54ace7, 0xbb362c3b, 0x3d80ab94, 
    0x3d1b533d, 0x3bcbcedf, 0xbd6118d3, 0xbdbea238, 0xbbbd39e4, 0xbd59a832, 0xbdaaf38e, 0xbc513a39, 
    0x3aee5916, 0xbc23db09, 0xbc2624aa, 0x3dbe613d, 0xbd078c33, 0x3d0150ed, 0x3c0bb81d, 0x3cb63133, 
    0xbd681af5, 0x3d2f168e, 0x3c00b968, 0xbd9b1ea5, 0xbd8b9115, 0xbd61af7e, 0xbd41c1ae, 0x3ce57e93, 
    0xbd726dc2, 0x3a595d9f, 0x3cdfd2f4, 0x3cd88da8, 0xbc2ac678, 0xbb75c4d5, 0xbc5f506d, 0x3d0ff2fe, 
    0xbd6370da, 0x3d8b62d0, 0xbd10bd76, 0xbd91d58a, 0xbaa5f42e, 0x3cdbe730, 0x3ca57ab7, 0xbac943b9, 
    0xbd68c485, 0x3d4fb78a, 0xbc0a8604, 0xbda06714, 0xbc7ff9b4, 0x3d3bfd15, 0x3c05682a, 0x3d4ba03d, 
    0x3d8c4669, 0x3cd8eff3, 0x3de8910b, 0x3da52e51, 0x3c92a9de, 0xbbe8eaf4, 0xbd9628c2, 0xbdaadcb5, 
    0xbd4d0db9, 0xbcf9e41f, 0xbc93317f, 0xbd8ddb8c, 0xbdfe5e35, 0xbdf4041b, 0xbd721e3c, 0xbc2c5ab9, 
    0xbdd8cd49, 0xbd5954e6, 0xbdca61bf, 0x3d24dc12, 0xbd0f2f18, 0xbd9a416d, 0x3cb3a666, 0x3d054ec5, 
    0xbdbb596f, 0xbd41fdf6, 0xbcf194e5, 0x3cad15d6, 0x3cc8e6ae, 0xbcf7716d, 0x3c040eb2, 0x3d5b73aa, 
    0x3d5fee27, 0xbd05310c, 0xbdc49fd8, 0xbd768437, 0x3cf228f6, 0xbdb68deb, 0xbca4927a, 0xbbbb41b8, 
    0x3c2fd0d7, 0x3cca6b3c, 0x3d252de4, 0x3dbcd19f, 0x3d323d07, 0x3b609fce, 0xbb874395, 0xbd9bc622, 
    0x3d255f03, 0x3d71e9c1, 0xbc04b3a7, 0x3c869bcb, 0x3ce02418, 0x3c2a1767, 0x3d3d512c, 0xbd07ae3b, 
    0x3d9d87cc, 0x3d7fe041, 0xbbe3c96a, 0x3d970716, 0x3d804f03, 0x3d0d79aa, 0xbd51258c, 0xbc1baad3, 
    0x3c9d974a, 0xbc692c81, 0x3d53dc70, 0xbc2d8089, 0xbd476c3e, 0xbd19407e, 0xbcb9f70b, 0x3cf09c53, 
    0x3d322293, 0x3d30ccd9, 0x3dc72718, 0xbd3743c2, 0x3d29f285, 0xbc90d3a9, 0xbd54696a, 0x3d8abb34, 
    0x3d864d23, 0xbc87938b, 0xbb6eef50, 0xbcd6e3ea, 0x3cfd4e09, 0x3c141884, 0xbcbc4d8d, 0x3b50b3ca, 
    0x3c7b35d3, 0x3c24da56, 0x3c2958b9, 0x3c5ba8fa, 0x3d94a64a, 0xbc4587c6, 0x3c18ecb0, 0x3d2a094a, 
    0x3d25bef2, 0xbd52a24e, 0xbc8844f9, 0x3cb85d86, 0x3c17e34e, 0x3d663135, 0x3d8fadd9, 0x3d317f76, 
    0xbc4c0e29, 0x3db96550, 0xbd1b6e86, 0x3d7d20cc, 0x3d0a7970, 0xbd424b39, 0xbd93d8cd, 0x3d352e8e, 
    0x3d698b91, 0x3c504582, 0x3b0a68b9, 0x3cd60efd, 0xbc969a23, 0xba0a4777, 0xbd53d238, 0x3d67e3c3, 
    0xbc90f652, 0xbd836b22, 0x3ca8bf4a, 0x3c84ee89, 0x3c3da467, 0x3b90bd0f, 0x3d51e5e8, 0x3d76d865, 
    0xbd17c3a1, 0xbd0b5628, 0xbc4cbc85, 0x3d9dbd33, 0x3dd55f3e, 0x3d9e3b68, 0x3d68bb58, 0xbaed29e1, 
    0xbcc517eb, 0xbbd5e498, 0xbbbcd83e, 0x3c964ff1, 0xbcf1cb4f, 0xba2218cb, 0x3d7c4bb3, 0x3c0e0138, 
    0x3da9baf3, 0x3d47349a, 0xbc3cbccf, 0x3d02f6a9, 0xbc8b007e, 0x3cd37565, 0xbd516f14, 0xbc855ab2, 
    0x3d8d08a6, 0x3cd2dc06, 0x3d91d497, 0x3d1bad6b, 0x3d88548b, 0xbd773537, 0x3bf6fd4e, 0xbc205f3e, 
    0xbcafa314, 0xbcc2b50d, 0x3d0af4b6, 0x3b4e938c, 0xbd05bfe1, 0xbb2390d4, 0x3ca5ae3f, 0x39a94931, 
    0xbb780cee, 0xbc9c045f, 0xbc421fa7, 0xbd061d61, 0x3c4bafb6, 0x3c252bfc, 0x3df18d17, 0x3d542e6d, 
    0x3d3ed63c, 0x3e0f28d3, 0x3d84b299, 0x3d5dcf99, 0xbc9f2860, 0x3d7fa2a6, 0xbd8e3121, 0xbc20f182, 
    0x3cccec5d, 0xbd250ea1, 0x3d55fbb4, 0xbd592bab, 0x3ca78e1c, 0x3d30da40, 0xbb45ec62, 0xbd38bf98, 
    0xbd321828, 0xbd14dc1a, 0xbc494e92, 0xbc8fe58c, 0x3d273ddc, 0xbc4bb15d, 0xbd2ddc3a, 0x3d6926b7, 
    0x3d2b7f39, 0xbd765c44, 0x3c5a437e, 0xbd4345c8, 0xbd2cfd5d, 0xbdbfd46e, 0x3d191786, 0x3c895807, 
    0x3d1bf512, 0xbcbefb24, 0x3da46a49, 0x3d0066b8, 0x3be15192, 0x3d8b05e3, 0x3e0aa6a0, 0xbca76fa1, 
    0x3d8c5aca, 0x3d8146b4, 0x3d518dbf, 0x3d4936f6, 0x3da1f482, 0xbd02a3b3, 0x3ae09d5a, 0xbc119da1, 
    0x3c0bef81, 0x3d8e2a17, 0xbc12bccb, 0x3cfa1952, 0x3d4e517c, 0x3d01c3ac, 0xbd131824, 0x3ba0c44e, 
    0x3c85787e, 0x3cfc12e0, 0xbc864840, 0x3d1a0c32, 0x3dbd09db, 0x3d07417f, 0x3d108ce1, 0x3d24380b, 
    0x3c02bfa5, 0x3c00b992, 0xbd0f90f9, 0x3ba20cdb, 0xbd52144a, 0xbdae5e4e, 0x3cb19b98, 0x3d5234fb, 
    0x3d52146d, 0xbd0885a7, 0x3e092b7f, 0xbd69dd58, 0x3cf13799, 0xb9ad21d8, 0xbbc53d3a, 0x3d803546, 
    0x3c869c55, 0x3dd869f5, 0x3da3fcad, 0xb9940633, 0x3b568d5a, 0xbc1d2f99, 0x3d1c5ea4, 0xbcf330a6, 
    0x3d49a56f, 0xbd0b0d60, 0x3c8459da, 0xbcd49c19, 0xbceab40e, 0xbca896a8, 0xbd8524aa, 0xbbc24916, 
    0x3bc27a6b, 0x3d06eb61, 0x3daebd0a, 0xbc8cf96d, 0xbce62462, 0xbd000ead, 0xbcded3c9, 0x3da37c36, 
    0xbc6dc687, 0x3ce1462b, 0x3d271e66, 0x3cdec711, 0xbd88b179, 0x3c63f0bf, 0xbd83b6a9, 0x39a39e84, 
    0x3ca2f96c, 0x3d8c95f5, 0x3e18fc8e, 0xbdfc54be, 0x3be7e58d, 0x3dfa32c4, 0x3d97f769, 0xbd316e35, 
    0xbdbb8e06, 0xbe25fe51, 0xbe3be113, 0xbd76d5fb, 0xbd798b73, 0xbd87f0cc, 0x3cf09937, 0xbcfd38f8, 
    0xbd2dafb3, 0xbd5c8d1e, 0x3cf41794, 0x3d9af7f6, 0x3c229e3b, 0x3d1ccba0, 0xbd0368e5, 0xbda30001, 
    0xbcdf0a4b, 0xbc8300c2, 0xbb0e2fdc, 0x3bde9b37, 0xbd3c95ad, 0x3cb39b66, 0xbd327e39, 0x3cd76e5a, 
    0x3d899685, 0x3bb00a50, 0x3b8f0249, 0x3d5f599f, 0x3d7b02cb, 0xbd1a01a1, 0xbcdc60af, 0xbdc13ff8, 
    0xbb15d488, 0xbd90c229, 0x3c23826c, 0xbd0a440b, 0x3c888f96, 0x3d9f6888, 0x3d865322, 0xbda78c5d, 
    0xbe3846ce, 0xbdcb4880, 0xbe3cc2de, 0xbd652fc6, 0xbd64bcce, 0xbd3184f4, 0xbb1bb640, 0xbd97932a, 
    0xbdcb7bd3, 0xbcbc3ca1, 0xbcf4b6cf, 0xbcc120ff, 0xbd35a408, 0xbce1f066, 0xbd10280b, 0x3c212f1f, 
    0xbd9a1f24, 0x3d62bfc8, 0x3c52a608, 0xbcf351be, 0xbc6d7997, 0xbaa82b49, 0xbd54131b, 0x3c272e12, 
    0xbc76ec75, 0xbb5c79d7, 0xb9cfe1cb, 0x3c9fb635, 0x3cc3725a, 0x3c66e0aa, 0xbc32f58c, 0x3ca975e8, 
    0xbc20a531, 0xbd260040, 0x3d86cda2, 0xbc0166f8, 0x3d68ef8f, 0x3df6fab9, 0x3e04ab20, 0xbce439b9, 
    0xbd9f5400, 0xbdbf25c2, 0xbdb1142c, 0xbd57330d, 0xbdc83815, 0xbda410c1, 0x3d1e2923, 0xbcbc32a9, 
    0xbd7280a2, 0x3d6cd980, 0xbbdcaa1e, 0x3d8bf40b, 0xbd2a2f22, 0x3d48a204, 0x3ce208af, 0xbd61dc0d, 
    0x3d354035, 0x3bae90ae, 0x3c7b6799, 0xbd583ee6, 0xbd68c170, 0x3c714286, 0x3d901d0d, 0x3da8d287, 
    0xbcd4c2ec, 0xbbb9f21c, 0xbcc9c5be, 0x3d18057b, 0x3cbd15f2, 0x3d890381, 0xbd014223, 0xbc4a390c, 
    0xbcab348c, 0xbc79463d, 0xbd204e1d, 0xfffffe76, 0x00000004, 0x00000040, 0xbddeeb48, 0xbdf33ce6, 
    0x3f0247bd, 0xbf2c5743, 0x3ed2d7fc, 0x3f03c016, 0xbf21103f, 0x3e92aaaa, 0xbe1d3ef7, 0xbf97beca, 
    0xbf0349dd, 0xbf3f4240, 0xbeae20cf, 0x3edf4ca4, 0xbf198f85, 0xbf1cb579, 0xfffffec2, 0x00000004, 
    0x00000040, 0x3c30036a, 0x3e185811, 0xbeb6450e, 0x384df800, 0xbf397699, 0xbf3e249a, 0x3f28b4c4, 
    0xbe011773, 0xbe2a7e78, 0xbdbc6491, 0xbfb33cce, 0xbf240448, 0x3e5e3b86, 0x3fdd2b18, 0xbffcb198, 
    0x3fd3491d, 0xffffff0e, 0x00000004, 0x00000040, 0xbf8c3b35, 0x3f843003, 0xbf984f13, 0x3ef50504, 
    0xbf9b8ee7, 0xbf838132, 0x3fa4cbe4, 0xbf935fda, 0x3f2d08ac, 0x3f6ea13e, 0xbf7bcb72, 0xbf792ad4, 
    0x3fca19c7, 0xbf94c9bc, 0xbfa0f550, 0x3fcbfbeb, 0xffffe650, 0xffffe654, 0x0000000f, 0x52494c4d, 
    0x6e6f4320, 0x74726576, 0x002e6465, 0x00000001, 0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 
    0x00040008, 0x0000000e, 0x00000014, 0x0000001c, 0x0000039c, 0x000003a0, 0x000003a4, 0x00000004, 
    0x6e69616d, 0x00000000, 0x0000000c, 0x00000360, 0x00000304, 0x000002b0, 0x0000026c, 0x00000248, 
    0x000001f4, 0x000001d0, 0x0000012c, 0x000000bc, 0x00000078, 0x00000040, 0x00000004, 0xfffffd36, 
    0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 0x00000006, 0x00060000, 0x00040008, 0x00000006, 
    0x3f800000, 0x00000001, 0x00000029, 0x00000001, 0x00000028, 0xfffffd6e, 0x00000014, 0x08000000, 
    0x00000010, 0x00000014, 0x00000005, 0xffffe72c, 0x00000001, 0x00000028, 0x00000003, 0x00000027, 
    0x00000019, 0xffffffff, 0xfffffda2, 0x0000001c, 0x08000000, 0x0000001c, 0x00000020, 0x00000005, 
    0x00060000, 0x00070008, 0x00000006, 0x01000000, 0x00000001, 0x00000027, 0x00000003, 0x00000026, 
    0x0000000a, 0x0000000b, 0xfffffde2, 0x00000024, 0x20000000, 0x0000002c, 0x00000030, 0x00000004, 
    0x000e0000, 0x000c0010, 0x00000008, 0x00040000, 0x0000000e, 0x00000002, 0x00000005, 0x00000005, 
    0x00000001, 0x00000026, 0x00000004, 0x00000025, 0x0000001a, 0x0000001b, 0x0000001c, 0x00160000, 
    0x0018001c, 0x00100014, 0x0008000f, 0x00000000, 0x00040000, 0x00000016, 0x00000018, 0x00000020, 
    0x47000000, 0x00000024, 0x00000028, 0x00000003, 0x00000000, 0x000c0008, 0x0004000b, 0x00000008, 
    0x41200000, 0x04000000, 0x00000001, 0x00000025, 0x00000018, 0x00000023, 0x00000015, 0x00000016, 
    0x00000017, 0x00000018, 0x0000000d, 0x0000000e, 0x0000000f, 0x00000010, 0xffffffff, 0xffffffff, 
    0xffffffff, 0x00000011, 0x00000012, 0x00000013, 0x00000014, 0xffffffff, 0xffffffff, 0x0000000c, 
    0x00000024, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xfffffe92, 0x00000008, 0x0000000c, 
    0x00000001, 0x00000023, 0x00000002, 0x00000022, 0x00000009, 0xffffff0e, 0x00000024, 0x05000000, 
    0x00000034, 0x00000038, 0x00000002, 0x000e0000, 0x00170018, 0x000c0010, 0x00040008, 0x0000000e, 
    0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x01000000, 0x00000001, 0x00000022, 0x00000001, 
    0x00000021, 0xffffff02, 0x00000008, 0x0000000c, 0x00000001, 0x00000021, 0x00000002, 0x00000020, 
    0x00000008, 0xffffff7e, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffff70, 
    0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000020, 0x00000003, 0x0000001f, 0x00000006, 
    0x00000003, 0xffffffbe, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffffb0, 
    0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x0000001f, 0x00000003, 0x0000001e, 0x00000005, 
    0x00000002, 0x000e0000, 0x00140018, 0x000c0010, 0x0004000b, 0x0000000e, 0x00000020, 0x01000000, 
    0x00000028, 0x0000002c, 0x00000001, 0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 0x01000000, 
    0x00000001, 0x00000002, 0x00000001, 0x0000001e, 0x00000003, 0x0000001d, 0x00000004, 0x00000001, 
    0x000a0000, 0x0000000c, 0x00040008, 0x0000000a, 0x00000008, 0x0000000c, 0x00000001, 0x0000001d, 
    0x00000002, 0x00000000, 0x00000007, 0x00000001, 0x00000029, 0x00000001, 0x00000000, 0x0000002a, 
    0x000015a8, 0x0000152c, 0x000014c8, 0x00001464, 0x0000131c, 0x000011d4, 0x000010c0, 0x00001054, 
    0x00000fd4, 0x00000f70, 0x00000f04, 0x00000e9c, 0x00000e3c, 0x00000de4, 0x00000da4, 0x00000d64, 
    0x00000d24, 0x00000ce8, 0x00000cac, 0x00000c70, 0x00000c34, 0x00000bf4, 0x00000bb4, 0x00000b70, 
    0x00000b2c, 0x00000ac8, 0x00000a84, 0x00000a40, 0x000009fc, 0x00000984, 0x0000079c, 0x000005b4, 
    0x000003fc, 0x0000038c, 0x00000320, 0x000002b8, 0x00000258, 0x00000200, 0x000001bc, 0x000000b4, 
    0x00000050, 0x00000004, 0xffffeb16, 0x01000000, 0x00000010, 0x00000010, 0x0000002a, 0x00000028, 
    0xffffeb00, 0x00000019, 0x74617453, 0x6c756665, 0x74726150, 0x6f697469, 0x4364656e, 0x3a6c6c61, 
    0x00000030, 0x00000002, 0x00000001, 0x00000004, 0xffffeb5e, 0x01000000, 0x00000010, 0x00000010, 
    0x00000029, 0x00000040, 0xffffeb48, 0x00000032, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x4d2f3631, 0x754d7461, 
    0x0000316c, 0x00000002, 0x00000001, 0x00000004, 0xffffebbe, 0x01000000, 0x00000010, 0x00000010, 
    0x00000028, 0x000000e4, 0xffffeba8, 0x000000d7, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x4d2f3231, 0x754d7461, 
    0x6f6d3b6c, 0x2f6c6564, 0x766e6f63, 0x736c6431, 0x732d6d74, 0x6c6c616d, 0x6363612d, 0x63617275, 
    0x2f312d79, 0x6579616c, 0x33315f72, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x315f6c75, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x74736c64, 0x6d732d6d, 0x2d6c6c61, 0x75636361, 0x79636172, 0x6c2f312d, 
    0x72657961, 0x2f34315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x74736c64, 0x6d732d6d, 
    0x2d6c6c61, 0x75636361, 0x79636172, 0x6c2f312d, 0x72657961, 0x2f33315f, 0x63746162, 0x726f6e68, 
    0x64612f6d, 0x00315f64, 0x00000002, 0x00000001, 0x00000028, 0xffffecc2, 0x01000000, 0x00000010, 
    0x00000010, 0x00000027, 0x00000020, 0xffffecac, 0x00000011, 0x2e6c6674, 0x69727473, 0x5f646564, 
    0x63696c73, 0x00000065, 0x00000002, 0x00000001, 0x00000010, 0xffffed02, 0x01000000, 0x00000010, 
    0x00000010, 0x00000026, 0x00000030, 0xffffecec, 0x00000020, 0x2e6c6674, 0x64696e75, 0x63657269, 
    0x6e6f6974, 0x735f6c61, 0x65757165, 0x5f65636e, 0x6d74736c, 0x00000000, 0x00000003, 0x00000001, 
    0x0000004b, 0x00000010, 0xfffff492, 0x01010000, 0x0000000c, 0x0000000c, 0x00000040, 0xffffed3c, 
    0x00000031, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 
    0x2d796361, 0x616c2f31, 0x5f726579, 0x7a2f3031, 0x736f7265, 0x00000031, 0x00000002, 0x00000001, 
    0x00000010, 0xffffedb2, 0x01000000, 0x00000010, 0x00000010, 0x00000024, 0x00000040, 0xffffed9c, 
    0x00000032, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 
    0x2d796361, 0x616c2f31, 0x5f726579, 0x71532f39, 0x7a656575, 0x00003165, 0x00000003, 0x00000001, 
    0x0000004b, 0x00000010, 0xffffee16, 0x01000000, 0x00000010, 0x00000010, 0x00000023, 0x00000040, 
    0xffffee00, 0x00000031, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x614d2f39, 0x6f6f5078, 0x0000006c, 0x00000004, 
    0x00000001, 0x0000004b, 0x00000001, 0x00000010, 0xffffee7e, 0x01000000, 0x00000010, 0x00000010, 
    0x00000022, 0x00000044, 0xffffee68, 0x00000035, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x78452f39, 0x646e6170, 
    0x736d6944, 0x00000031, 0x00000004, 0x00000001, 0x00000096, 0x00000001, 0x00000010, 0xffffeeea, 
    0x01000000, 0x00000010, 0x00000010, 0x00000021, 0x0000018c, 0xffffeed4, 0x0000017c, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 
    0x5f726579, 0x65522f38, 0x6d3b756c, 0x6c65646f, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 
    0x63612d6c, 0x61727563, 0x312d7963, 0x79616c2f, 0x375f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 
    0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x74736c64, 0x6d732d6d, 0x2d6c6c61, 0x75636361, 
    0x79636172, 0x6c2f312d, 0x72657961, 0x432f365f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 
    0x2f6c6564, 0x766e6f63, 0x736c6431, 0x732d6d74, 0x6c6c616d, 0x6363612d, 0x63617275, 0x2f312d79, 
    0x6579616c, 0x2f375f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 
    0x61622f37, 0x6e686374, 0x2f6d726f, 0x3b6c756d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f37, 0x6e686374, 
    0x2f6d726f, 0x3b627573, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x6f432f36, 0x4431766e, 0x00000000, 0x00000004, 
    0x00000001, 0x00000001, 0x00000096, 0x00000010, 0xfffff09e, 0x01000000, 0x00000010, 0x00000010, 
    0x00000020, 0x000001bc, 0xfffff088, 0x000001ad, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x65522f35, 0x6d3b756c, 
    0x6c65646f, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 0x312d7963, 
    0x79616c2f, 0x345f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 
    0x31766e6f, 0x74736c64, 0x6d732d6d, 0x2d6c6c61, 0x75636361, 0x79636172, 0x6c2f312d, 0x72657961, 
    0x432f335f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 0x736c6431, 
    0x732d6d74, 0x6c6c616d, 0x6363612d, 0x63617275, 0x2f312d79, 0x6579616c, 0x2f345f72, 0x63746162, 
    0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 
    0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f34, 0x6e686374, 0x2f6d726f, 
    0x3b6c756d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 
    0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f34, 0x6e686374, 0x2f6d726f, 0x3b627573, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 
    0x5f726579, 0x6f432f36, 0x4431766e, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x74736c64, 0x6d732d6d, 
    0x2d6c6c61, 0x75636361, 0x79636172, 0x6c2f312d, 0x72657961, 0x432f335f, 0x31766e6f, 0x00000044, 
    0x00000004, 0x00000001, 0x00000001, 0x00000096, 0x00000010, 0xfffff282, 0x01000000, 0x00000010, 
    0x00000010, 0x0000001f, 0x000001bc, 0xfffff26c, 0x000001ad, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x65522f32, 
    0x6d3b756c, 0x6c65646f, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 
    0x312d7963, 0x79616c2f, 0x315f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x74736c64, 0x6d732d6d, 0x2d6c6c61, 0x75636361, 0x79636172, 0x6c2f312d, 
    0x72657961, 0x432f305f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 
    0x736c6431, 0x732d6d74, 0x6c6c616d, 0x6363612d, 0x63617275, 0x2f312d79, 0x6579616c, 0x2f315f72, 
    0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f31, 0x6e686374, 
    0x2f6d726f, 0x3b6c756d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f31, 0x6e686374, 0x2f6d726f, 0x3b627573, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 
    0x616c2f31, 0x5f726579, 0x6f432f36, 0x4431766e, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x74736c64, 
    0x6d732d6d, 0x2d6c6c61, 0x75636361, 0x79636172, 0x6c2f312d, 0x72657961, 0x432f305f, 0x31766e6f, 
    0x00000044, 0x00000004, 0x00000001, 0x00000001, 0x00000096, 0x00000010, 0xfffff466, 0x01000000, 
    0x00000010, 0x00000010, 0x0000001e, 0x0000004c, 0xfffff450, 0x0000003c, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 
    0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 0x31736d69, 0x00000000, 0x00000004, 0x00000001, 
    0x00000001, 0x0000012c, 0x00000028, 0xfffffa12, 0x01000000, 0x00000014, 0x00000014, 0x0000001d, 
    0x02000000, 0x00000020, 0xfffff4c8, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3431746e, 
    0x00000000, 0x00000001, 0x00000003, 0xfffffa52, 0x01000000, 0x00000014, 0x00000014, 0x0000001c, 
    0x02000000, 0x00000020, 0xfffff508, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3331746e, 
    0x00000000, 0x00000001, 0x00000003, 0xfffffa92, 0x01000000, 0x00000014, 0x00000014, 0x0000001b, 
    0x02000000, 0x00000020, 0xfffff548, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3231746e, 
    0x00000000, 0x00000001, 0x00000003, 0xfffff59a, 0x01000000, 0x00000010, 0x00000010, 0x0000001a, 
    0x00000040, 0xfffff584, 0x00000031, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 
    0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x4d2f3631, 0x754d7461, 0x0000006c, 
    0x00000002, 0x00000004, 0x00000028, 0xfffff5fa, 0x01000000, 0x00000010, 0x00000010, 0x00000019, 
    0x00000020, 0xfffff5e4, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3131746e, 0x00000000, 
    0x00000002, 0x00000010, 0x00000010, 0xfffff63a, 0x01000000, 0x00000010, 0x00000010, 0x00000018, 
    0x00000020, 0xfffff624, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3031746e, 0x00000000, 
    0x00000002, 0x00000010, 0x00000010, 0xfffff67a, 0x01000000, 0x00000010, 0x00000010, 0x00000017, 
    0x0000001c, 0xfffff664, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0039746e, 0x00000002, 
    0x00000010, 0x00000010, 0xfffff6b6, 0x01000000, 0x00000010, 0x00000010, 0x00000016, 0x0000001c, 
    0xfffff6a0, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0038746e, 0x00000002, 0x00000010, 
    0x00000010, 0xfffff6f2, 0x01000000, 0x00000010, 0x00000010, 0x00000015, 0x0000001c, 0xfffff6dc, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0037746e, 0x00000001, 0x00000010, 0xfffff72a, 
    0x01000000, 0x00000010, 0x00000010, 0x00000014, 0x0000001c, 0xfffff714, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x00000010, 0xfffff762, 0x01000000, 0x00000010, 
    0x00000010, 0x00000013, 0x0000001c, 0xfffff74c, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0035746e, 0x00000001, 0x00000010, 0xfffff79a, 0x01000000, 0x00000010, 0x00000010, 0x00000012, 
    0x0000001c, 0xfffff784, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0034746e, 0x00000001, 
    0x00000010, 0xfffff7d2, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 0x0000001c, 0xfffff7bc, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0033746e, 0x00000002, 0x00000010, 0x00000010, 
    0xfffff80e, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x0000001c, 0xfffff7f8, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 0x00000002, 0x00000010, 0x00000010, 0xfffff84a, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000f, 0x0000001c, 0xfffff834, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0031746e, 0x00000002, 0x00000010, 0x00000010, 0xfffff886, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000e, 0x0000001c, 0xfffff870, 0x0000000e, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0000746e, 0x00000002, 0x00000010, 0x00000010, 0x00160000, 0x00100014, 0x00000000, 
    0x0008000c, 0x00000007, 0x00060000, 0x00000016, 0x01010000, 0x0000000c, 0x0000000c, 0x00000040, 
    0xfffff8c0, 0x00000030, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x7a2f3031, 0x736f7265, 0x00000000, 0x00000002, 
    0x00000001, 0x00000010, 0xfffff936, 0x01000000, 0x00000010, 0x00000010, 0x0000000c, 0x00000048, 
    0xfffff920, 0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x622f3331, 0x68637461, 0x6d726f6e, 0x6275732f, 
    0x00000000, 0x00000001, 0x00000028, 0xfffff99a, 0x01000000, 0x00000010, 0x00000010, 0x0000000b, 
    0x00000048, 0xfffff984, 0x0000003a, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 
    0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x622f3331, 0x68637461, 0x6d726f6e, 
    0x6c756d2f, 0x0000315f, 0x00000002, 0x00000028, 0x00000010, 0xffffff3a, 0x01000000, 0x00000014, 
    0x00000014, 0x0000000a, 0x02000000, 0x00000040, 0xfffff9f0, 0x00000031, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 
    0x71532f39, 0x7a656575, 0x00000065, 0x00000001, 0x00000003, 0xffffff9a, 0x01000000, 0x00000014, 
    0x00000014, 0x00000009, 0x02000000, 0x00000044, 0xfffffa50, 0x00000034, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 
    0x78452f39, 0x646e6170, 0x736d6944, 0x00000000, 0x00000001, 0x00000004, 0x00160000, 0x0018001c, 
    0x00100017, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 
    0x00000008, 0x02000000, 0x00000048, 0xfffffacc, 0x0000003b, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x6f432f30, 
    0x4431766e, 0x7078452f, 0x44646e61, 0x00736d69, 0x00000001, 0x00000004, 0xfffffb46, 0x01000000, 
    0x00000010, 0x00000010, 0x00000007, 0x000000e8, 0xfffffb30, 0x000000db, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 
    0x61622f37, 0x6e686374, 0x2f6d726f, 0x5f6c756d, 0x6f6d3b31, 0x2f6c6564, 0x766e6f63, 0x736c6431, 
    0x732d6d74, 0x6c6c616d, 0x6363612d, 0x63617275, 0x2f312d79, 0x6579616c, 0x2f365f72, 0x766e6f43, 
    0x532f4431, 0x65657571, 0x6d3b657a, 0x6c65646f, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 
    0x63612d6c, 0x61727563, 0x312d7963, 0x79616c2f, 0x375f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 
    0x6d3b6c75, 0x6c65646f, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 
    0x312d7963, 0x79616c2f, 0x365f7265, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000010, 0x00000001, 
    0x00000003, 0x00000010, 0xfffffc56, 0x01000000, 0x00000010, 0x00000010, 0x00000006, 0x0000011c, 
    0xfffffc40, 0x0000010c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f34, 0x6e686374, 0x2f6d726f, 0x5f6c756d, 
    0x6f6d3b31, 0x2f6c6564, 0x766e6f63, 0x736c6431, 0x732d6d74, 0x6c6c616d, 0x6363612d, 0x63617275, 
    0x2f312d79, 0x6579616c, 0x2f335f72, 0x766e6f43, 0x532f4431, 0x65657571, 0x6d3b657a, 0x6c65646f, 
    0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 0x312d7963, 0x79616c2f, 
    0x345f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x6d3b6c75, 0x6c65646f, 0x6e6f632f, 0x6c643176, 
    0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 0x312d7963, 0x79616c2f, 0x335f7265, 0x6e6f432f, 
    0x3b443176, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 0x72756363, 
    0x2d796361, 0x616c2f31, 0x5f726579, 0x6f432f36, 0x4431766e, 0x00000000, 0x00000004, 0x00000010, 
    0x00000001, 0x00000003, 0x00000010, 0xfffffd9a, 0x01000000, 0x00000010, 0x00000010, 0x00000005, 
    0x0000011c, 0xfffffd84, 0x0000010c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 
    0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f31, 0x6e686374, 0x2f6d726f, 
    0x5f6c756d, 0x6f6d3b31, 0x2f6c6564, 0x766e6f63, 0x736c6431, 0x732d6d74, 0x6c6c616d, 0x6363612d, 
    0x63617275, 0x2f312d79, 0x6579616c, 0x2f305f72, 0x766e6f43, 0x532f4431, 0x65657571, 0x6d3b657a, 
    0x6c65646f, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 0x312d7963, 
    0x79616c2f, 0x315f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x6d3b6c75, 0x6c65646f, 0x6e6f632f, 
    0x6c643176, 0x2d6d7473, 0x6c616d73, 0x63612d6c, 0x61727563, 0x312d7963, 0x79616c2f, 0x305f7265, 
    0x6e6f432f, 0x3b443176, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 0x616d732d, 0x612d6c6c, 
    0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x6f432f36, 0x4431766e, 0x00000000, 0x00000004, 
    0x00000010, 0x00000001, 0x00000003, 0x00000028, 0xfffffede, 0x01000000, 0x00000010, 0x00000010, 
    0x00000004, 0x00000044, 0xfffffec8, 0x00000037, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f37, 0x6e686374, 
    0x2f6d726f, 0x00627573, 0x00000001, 0x00000010, 0xffffff3e, 0x01000000, 0x00000010, 0x00000010, 
    0x00000003, 0x00000044, 0xffffff28, 0x00000037, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f34, 0x6e686374, 
    0x2f6d726f, 0x00627573, 0x00000001, 0x00000010, 0xffffff9e, 0x01000000, 0x00000010, 0x00000010, 
    0x00000002, 0x00000044, 0xffffff88, 0x00000037, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x6d74736c, 
    0x616d732d, 0x612d6c6c, 0x72756363, 0x2d796361, 0x616c2f31, 0x5f726579, 0x61622f31, 0x6e686374, 
    0x2f6d726f, 0x00627573, 0x00000001, 0x00000010, 0x00160000, 0x00140018, 0x00100000, 0x0008000c, 
    0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000001, 0x0000002c, 
    0x00040004, 0x00000004, 0x00000019, 0x76726573, 0x5f676e69, 0x61666564, 0x5f746c75, 0x75706e69, 
    0x3a315f74, 0x00000030, 0x00000003, 0x00000001, 0x0000012c, 0x00000028, 0x00000007, 0x00000070, 
    0x00000054, 0x00000044, 0x00000034, 0x00000024, 0x00000014, 0x00000004, 0xffffffb8, 0x00000019, 
    0x19000000, 0xffffffc4, 0x00000009, 0x09000000, 0xffffffd0, 0x0000002d, 0x2d000000, 0xffffffdc, 
    0x0000002c, 0x2c000000, 0xffffffe8, 0x00000011, 0x11000000, 0xfffffff4, 0x00000003, 0x03000000, 
    0x000c000c, 0x0000000b, 0x00040000, 0x0000000c, 0x00000016, 0x16000000
};

static const uint32_t _K11[] = {
    0x3da3d70a, 0x3da3e945, 0x3da41ff6, 0x3da47b1a, 0x3da4faae, 0x3da59ead, 0x3da66711, 0x3da753d1, 
    0x3da864e6, 0x3da99a43, 0x3daaf3de, 0x3dac71a8, 0x3dae1393, 0x3dafd990, 0x3db1c38b, 0x3db3d173, 
    0x3db60333, 0x3db858b5, 0x3dbad1e2, 0x3dbd6ea1, 0x3dc02eda, 0x3dc3126f, 0x3dc61946, 0x3dc9433f, 
    0x3dcc903c, 0x3dd0001c, 0x3dd392bc, 0x3dd747fa, 0x3ddb1fb0, 0x3ddf19b9, 0x3de335ed, 0x3de77423, 
    0x3debd432, 0x3df055ed, 0x3df4f929, 0x3df9bdb7, 0x3dfea369, 0x3e01d506, 0x3e0468b9, 0x3e070cb2, 
    0x3e09c0d8, 0x3e0c8510, 0x3e0f593f, 0x3e123d48, 0x3e15310f, 0x3e183476, 0x3e1b4760, 0x3e1e69af, 
    0x3e219b42, 0x3e24dbfc, 0x3e282bba, 0x3e2b8a5d, 0x3e2ef7c4, 0x3e3273cb, 0x3e35fe51, 0x3e399733, 
    0x3e3d3e4d, 0x3e40f37b, 0x3e44b697, 0x3e48877d, 0x3e4c6608, 0x3e50520f, 0x3e544b6e, 0x3e5851fc, 
    0x3e5c6591, 0x3e608606, 0x3e64b330, 0x3e68ece8, 0x3e6d3302, 0x3e718555, 0x3e75e3b6, 0x3e7a4df9, 
    0x3e7ec3f3, 0x3e81a2bc, 0x3e83e92d, 0x3e863537, 0x3e8886c2, 0x3e8addb8, 0x3e8d3a02, 0x3e8f9b87, 
    0x3e920232, 0x3e946de9, 0x3e96de94, 0x3e99541c, 0x3e9bce69, 0x3e9e4d61, 0x3ea0d0ec, 0x3ea358f1, 
    0x3ea5e557, 0x3ea87604, 0x3eab0ae0, 0x3eada3d1, 0x3eb040bc, 0x3eb2e189, 0x3eb5861c, 0x3eb82e5d, 
    0x3ebada30, 0x3ebd897b, 0x3ec03c23, 0x3ec2f20e, 0x3ec5ab21, 0x3ec86741, 0x3ecb2653, 0x3ecde83b, 
    0x3ed0acdf, 0x3ed37422, 0x3ed63de9, 0x3ed90a1a, 0x3edbd897, 0x3edea945, 0x3ee17c09, 0x3ee450c6, 
    0x3ee72760, 0x3ee9ffbb, 0x3eecd9bb, 0x3eefb544, 0x3ef29239, 0x3ef5707e, 0x3ef84ff6, 0x3efb3086, 
    0x3efe1210, 0x3f007a3c, 0x3f01ebd1, 0x3f035db8, 0x3f04cfe4, 0x3f064245, 0x3f07b4ce, 0x3f09276f, 
    0x3f0a9a1c, 0x3f0c0cc5, 0x3f0d7f5c, 0x3f0ef1d3, 0x3f10641b, 0x3f11d626, 0x3f1347e6, 0x3f14b94c, 
    0x3f162a4a, 0x3f179ad3, 0x3f190ad7, 0x3f1a7a48, 0x3f1be918, 0x3f1d5739, 0x3f1ec49d, 0x3f203136, 
    0x3f219cf5, 0x3f2307cc, 0x3f2471ae, 0x3f25da8c, 0x3f274259, 0x3f28a906, 0x3f2a0e86, 0x3f2b72ca, 
    0x3f2cd5c6, 0x3f2e376a, 0x3f2f97ab, 0x3f30f679, 0x3f3253c7, 0x3f33af88, 0x3f3509af, 0x3f36622d, 
    0x3f37b8f7, 0x3f390dfd, 0x3f3a6134, 0x3f3bb28d, 0x3f3d01fd, 0x3f3e4f76, 0x3f3f9aea, 0x3f40e44e, 
    0x3f422b95, 0x3f4370b1, 0x3f44b397, 0x3f45f439, 0x3f47328c, 0x3f486e82, 0x3f49a811, 0x3f4adf2b, 
    0x3f4c13c5, 0x3f4d45d2, 0x3f4e7547, 0x3f4fa219, 0x3f50cc3a, 0x3f51f3a1, 0x3f531841, 0x3f543a0f, 
    0x3f555901, 0x3f56750a, 0x3f578e20, 0x3f58a437, 0x3f59b746, 0x3f5ac742, 0x3f5bd420, 0x3f5cddd5, 
    0x3f5de457, 0x3f5ee79d, 0x3f5fe79c, 0x3f60e44a, 0x3f61dd9d, 0x3f62d38c, 0x3f63c60e, 0x3f64b518, 
    0x3f65a0a2, 0x3f6688a3, 0x3f676d11, 0x3f684de4, 0x3f692b13, 0x3f6a0495, 0x3f6ada62, 0x3f6bac72, 
    0x3f6c7abd, 0x3f6d453a, 0x3f6e0be2, 0x3f6ecead, 0x3f6f8d94, 0x3f70488f, 0x3f70ff97, 0x3f71b2a4, 
    0x3f7261b1, 0x3f730cb6, 0x3f73b3ac, 0x3f74568d, 0x3f74f553, 0x3f758ff8, 0x3f762676, 0x3f76b8c6, 
    0x3f7746e3, 0x3f77d0c8, 0x3f78566f, 0x3f78d7d4, 0x3f7954f0, 0x3f79cdc0, 0x3f7a423f, 0x3f7ab267, 
    0x3f7b1e35, 0x3f7b85a5, 0x3f7be8b3, 0x3f7c475a, 0x3f7ca197, 0x3f7cf767, 0x3f7d48c6, 0x3f7d95b2, 
    0x3f7dde26, 0x3f7e2221, 0x3f7e619f, 0x3f7e9c9f, 0x3f7ed31e, 0x3f7f051a, 0x3f7f3290, 0x3f7f5b80, 
    0x3f7f7fe7, 0x3f7f9fc5, 0x3f7fbb17, 0x3f7fd1dd, 0x3f7fe416, 0x3f7ff1c2, 0x3f7ffadf, 0x3f7fff6e, 
    0x3f7fff6e, 0x3f7ffadf, 0x3f7ff1c2, 0x3f7fe416, 0x3f7fd1dd, 0x3f7fbb17, 0x3f7f9fc5, 0x3f7f7fe7, 
    0x3f7f5b80, 0x3f7f3290, 0x3f7f051a, 0x3f7ed31e, 0x3f7e9c9f, 0x3f7e619f, 0x3f7e2221, 0x3f7dde26, 
    0x3f7d95b2, 0x3f7d48c6, 0x3f7cf767, 0x3f7ca197, 0x3f7c475a, 0x3f7be8b3, 0x3f7b85a5, 0x3f7b1e35, 
    0x3f7ab267, 0x3f7a423f, 0x3f79cdc0, 0x3f7954f0, 0x3f78d7d4, 0x3f78566f, 0x3f77d0c8, 0x3f7746e3, 
    0x3f76b8c6, 0x3f762676, 0x3f758ff8, 0x3f74f553, 0x3f74568d, 0x3f73b3ac, 0x3f730cb6, 0x3f7261b1, 
    0x3f71b2a4, 0x3f70ff97, 0x3f70488f, 0x3f6f8d94, 0x3f6ecead, 0x3f6e0be2, 0x3f6d453a, 0x3f6c7abd, 
    0x3f6bac72, 0x3f6ada62, 0x3f6a0495, 0x3f692b13, 0x3f684de4, 0x3f676d11, 0x3f6688a3, 0x3f65a0a2, 
    0x3f64b518, 0x3f63c60e, 0x3f62d38c, 0x3f61dd9d, 0x3f60e44a, 0x3f5fe79c, 0x3f5ee79d, 0x3f5de457, 
    0x3f5cddd5, 0x3f5bd420, 0x3f5ac742, 0x3f59b746, 0x3f58a437, 0x3f578e20, 0x3f56750a, 0x3f555901, 
    0x3f543a0f, 0x3f531841, 0x3f51f3a1, 0x3f50cc3a, 0x3f4fa219, 0x3f4e7547, 0x3f4d45d2, 0x3f4c13c5, 
    0x3f4adf2b, 0x3f49a811, 0x3f486e82, 0x3f47328c, 0x3f45f439, 0x3f44b397, 0x3f4370b1, 0x3f422b95, 
    0x3f40e44e, 0x3f3f9aea, 0x3f3e4f76, 0x3f3d01fd, 0x3f3bb28d, 0x3f3a6134, 0x3f390dfd, 0x3f37b8f7, 
    0x3f36622d, 0x3f3509af, 0x3f33af88, 0x3f3253c7, 0x3f30f679, 0x3f2f97ab, 0x3f2e376a, 0x3f2cd5c6, 
    0x3f2b72ca, 0x3f2a0e86, 0x3f28a906, 0x3f274259, 0x3f25da8c, 0x3f2471ae, 0x3f2307cc, 0x3f219cf5, 
    0x3f203136, 0x3f1ec49d, 0x3f1d5739, 0x3f1be918, 0x3f1a7a48, 0x3f190ad7, 0x3f179ad3, 0x3f162a4a, 
    0x3f14b94c, 0x3f1347e6, 0x3f11d626, 0x3f10641b, 0x3f0ef1d3, 0x3f0d7f5c, 0x3f0c0cc5, 0x3f0a9a1c, 
    0x3f09276f, 0x3f07b4ce, 0x3f064245, 0x3f04cfe4, 0x3f035db8, 0x3f01ebd1, 0x3f007a3c, 0x3efe1210, 
    0x3efb3086, 0x3ef84ff6, 0x3ef5707e, 0x3ef29239, 0x3eefb544, 0x3eecd9bb, 0x3ee9ffbb, 0x3ee72760, 
    0x3ee450c6, 0x3ee17c09, 0x3edea945, 0x3edbd897, 0x3ed90a1a, 0x3ed63de9, 0x3ed37422, 0x3ed0acdf, 
    0x3ecde83b, 0x3ecb2653, 0x3ec86741, 0x3ec5ab21, 0x3ec2f20e, 0x3ec03c23, 0x3ebd897b, 0x3ebada30, 
    0x3eb82e5d, 0x3eb5861c, 0x3eb2e189, 0x3eb040bc, 0x3eada3d1, 0x3eab0ae0, 0x3ea87604, 0x3ea5e557, 
    0x3ea358f1, 0x3ea0d0ec, 0x3e9e4d61, 0x3e9bce69, 0x3e99541c, 0x3e96de94, 0x3e946de9, 0x3e920232, 
    0x3e8f9b87, 0x3e8d3a02, 0x3e8addb8, 0x3e8886c2, 0x3e863537, 0x3e83e92d, 0x3e81a2bc, 0x3e7ec3f3, 
    0x3e7a4df9, 0x3e75e3b6, 0x3e718555, 0x3e6d3302, 0x3e68ece8, 0x3e64b330, 0x3e608606, 0x3e5c6591, 
    0x3e5851fc, 0x3e544b6e, 0x3e50520f, 0x3e4c6608, 0x3e48877d, 0x3e44b697, 0x3e40f37b, 0x3e3d3e4d, 
    0x3e399733, 0x3e35fe51, 0x3e3273cb, 0x3e2ef7c4, 0x3e2b8a5d, 0x3e282bba, 0x3e24dbfc, 0x3e219b42, 
    0x3e1e69af, 0x3e1b4760, 0x3e183476, 0x3e15310f, 0x3e123d48, 0x3e0f593f, 0x3e0c8510, 0x3e09c0d8, 
    0x3e070cb2, 0x3e0468b9, 0x3e01d506, 0x3dfea369, 0x3df9bdb7, 0x3df4f929, 0x3df055ed, 0x3debd432, 
    0x3de77423, 0x3de335ed, 0x3ddf19b9, 0x3ddb1fb0, 0x3dd747fa, 0x3dd392bc, 0x3dd0001c, 0x3dcc903c, 
    0x3dc9433f, 0x3dc61946, 0x3dc3126f, 0x3dc02eda, 0x3dbd6ea1, 0x3dbad1e2, 0x3db858b5, 0x3db60333, 
    0x3db3d173, 0x3db1c38b, 0x3dafd990, 0x3dae1393, 0x3dac71a8, 0x3daaf3de, 0x3da99a43, 0x3da864e6, 
    0x3da753d1, 0x3da66711, 0x3da59ead, 0x3da4faae, 0x3da47b1a, 0x3da41ff6, 0x3da3e945, 0x3da3d70a
};

static const uint32_t _K23[] = {
    0x000b0009, 0x000f000d, 0x00130011, 0x00170015, 0x001d001a, 0x0022001f, 0x00290025, 0x0030002c, 
    0x00380034, 0x0040003c, 0x004a0045, 0x0055004f, 0x0061005b, 0x006e0067, 0x007d0076, 0x008e0085, 
    0x00a00097, 0x00b400aa, 0x00cb00bf, 0x00e400d7, 0x010000f2
};

// Memory mapped buffers
#define _K11             ((float *)_K11)                     // f32[512] (2048 bytes)
#define _K23             ((int16_t *)_K23)                   // s16[42] (84 bytes)
#define _K7              ((uint8_t *)_K7)                    // u8[33784] (33784 bytes)
#define _K10             ((int8_t *)(_state + 0x0000c520))   // s8[8] (8 bytes)
#define _K18             ((int32_t *)(_state + 0x00026928))  // s32[24] (96 bytes)
#define _K19             ((float *)(_state + 0x00026988))    // f32[258] (1032 bytes)
#define _K2              ((int8_t *)(_state + 0x00000000))   // s8[2256] (2256 bytes)
#define _K5              ((int8_t *)(_state + 0x000008d0))   // s8[48208] (48208 bytes)
#define _K6              ((uint8_t *)(_state + 0x0000c528))  // u8[107520] (107520 bytes)
#define _K1              ((float *)(_buffer + 0x00000000))   // f32[512] (2048 bytes)
#define _K15             ((float *)(_buffer + 0x00000800))   // f32[512] (2048 bytes)
#define _K16             ((float *)(_buffer + 0x00001000))   // f32[257,2] (2056 bytes)
#define _K20             ((float *)(_buffer + 0x00001808))   // f32[1026] (4104 bytes)
#define _K22             ((float *)(_buffer + 0x00000000))   // f32[257] (1028 bytes)
#define _K27             ((float *)(_buffer + 0x00000404))   // f32[40] (160 bytes)
#define _K28             ((float *)(_buffer + 0x00000000))   // f32[40] (160 bytes)
#define _K29             ((float *)(_buffer + 0x000000a0))   // f32[40] (160 bytes)
#define _K3              ((float *)(_buffer + 0x00000000))   // f32[40] (160 bytes)
#define _K4              ((float *)(_buffer + 0x00000000))   // f32[300,40] (48000 bytes)

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	dest->used = 0;
	dest->read = 0;
	dest->write = 0;
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t *buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;

	int c0 = count;
	if (a0 + c0 > buf->size)
		c0 = buf->size - a0;
	
	memcpy(dst, buf->buf + a0, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void *cbuffer_readptr(cbuffer_t* buf, int offset, int *can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeue(void* restrict handle, void* restrict dst, int count, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_ERROR;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_ERROR;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

// input array (any shape >= 1D)
// output array (same shape as input array)
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void hammingmul_f32(const float* restrict input, const float* restrict w, int d0, int d1, int d2, float* restrict output)
{
	const int d3 = d0 * d1;

	const float* ip = input;
	float* op = output;
 
	for (int j = 0; j < d2; j++) {
		for (int i = 0; i < d0; i++) {
			for (int k = 0; k < d1; k++) {
				op[k * d0 + i] = ip[k * d0 + i] * w[k];
			}
		}

		ip += d3;
		op += d3;
	}
}

static void makeipt(int nw, int *ip)
{
    int j, l, m, m2, p, q;
    
    ip[2] = 0;
    ip[3] = 16;
    m = 2;
    for (l = nw; l > 32; l >>= 2) {
        m2 = m << 1;
        q = m2 << 3;
        for (j = m; j < m2; j++) {
            p = ip[j] << 2;
            ip[m + j] = p;
            ip[m2 + j] = p + q;
        }
        m = m2;
    }
}

static void makewt(int nw, int *ip, float *w)
{
    void makeipt(int nw, int *ip);
    int j, nwh, nw0, nw1;
    float delta, wn4r, wk1r, wk1i, wk3r, wk3i;
    
    ip[0] = nw;
    ip[1] = 1;
    if (nw > 2) {
        nwh = nw >> 1;
        delta = atan(1.0) / nwh;
        wn4r = cos(delta * nwh);
        w[0] = 1;
        w[1] = wn4r;
        if (nwh == 4) {
            w[2] = cos(delta * 2);
            w[3] = sin(delta * 2);
        } else if (nwh > 4) {
            makeipt(nw, ip);
            w[2] = 0.5 / cos(delta * 2);
            w[3] = 0.5 / cos(delta * 6);
            for (j = 4; j < nwh; j += 4) {
                w[j] = cos(delta * j);
                w[j + 1] = sin(delta * j);
                w[j + 2] = cos(3 * delta * j);
                w[j + 3] = -sin(3 * delta * j);
            }
        }
        nw0 = 0;
        while (nwh > 2) {
            nw1 = nw0 + nwh;
            nwh >>= 1;
            w[nw1] = 1;
            w[nw1 + 1] = wn4r;
            if (nwh == 4) {
                wk1r = w[nw0 + 4];
                wk1i = w[nw0 + 5];
                w[nw1 + 2] = wk1r;
                w[nw1 + 3] = wk1i;
            } else if (nwh > 4) {
                wk1r = w[nw0 + 4];
                wk3r = w[nw0 + 6];
                w[nw1 + 2] = 0.5 / wk1r;
                w[nw1 + 3] = 0.5 / wk3r;
                for (j = 4; j < nwh; j += 4) {
                    wk1r = w[nw0 + 2 * j];
                    wk1i = w[nw0 + 2 * j + 1];
                    wk3r = w[nw0 + 2 * j + 2];
                    wk3i = w[nw0 + 2 * j + 3];
                    w[nw1 + j] = wk1r;
                    w[nw1 + j + 1] = wk1i;
                    w[nw1 + j + 2] = wk3r;
                    w[nw1 + j + 3] = wk3i;
                }
            }
            nw0 = nw1;
        }
    }
}

static void makect(int nc, int *ip, float *c)
{
    int j, nch;
    float delta;
    
    ip[1] = nc;
    if (nc > 1) {
        nch = nc >> 1;
        delta = atan(1.0) / nch;
        c[0] = cos(delta * nch);
        c[nch] = 0.5 * c[0];
        for (j = 1; j < nch; j++) {
            c[j] = 0.5 * cos(delta * j);
            c[nc - j] = 0.5 * sin(delta * j);
        }
    }
}

static void bitrv2(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    }
}

static void bitrv216(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x7r, x7i, x8r, x8i, x10r, x10i, 
        x11r, x11i, x12r, x12i, x13r, x13i, x14r, x14i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    a[2] = x8r;
    a[3] = x8i;
    a[4] = x4r;
    a[5] = x4i;
    a[6] = x12r;
    a[7] = x12i;
    a[8] = x2r;
    a[9] = x2i;
    a[10] = x10r;
    a[11] = x10i;
    a[14] = x14r;
    a[15] = x14i;
    a[16] = x1r;
    a[17] = x1i;
    a[20] = x5r;
    a[21] = x5i;
    a[22] = x13r;
    a[23] = x13i;
    a[24] = x3r;
    a[25] = x3i;
    a[26] = x11r;
    a[27] = x11i;
    a[28] = x7r;
    a[29] = x7i;
}

static void bitrv208(float *a)
{
    float x1r, x1i, x3r, x3i, x4r, x4i, x6r, x6i;
    
    x1r = a[2];
    x1i = a[3];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x6r = a[12];
    x6i = a[13];
    a[2] = x4r;
    a[3] = x4i;
    a[6] = x6r;
    a[7] = x6i;
    a[8] = x1r;
    a[9] = x1i;
    a[12] = x3r;
    a[13] = x3i;
}

static void cftf1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = a[j + 3] + a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = a[j + 3] - a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = a[j0 - 1] + a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = a[j0 - 1] - a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = a[j0 - 1] + a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = a[j0 - 1] - a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i + x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = a[j0 + 3] + a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = a[j0 + 3] - a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i + x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftmdl1(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    k = 0;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
    }
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
}

static void cftmdl2(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, kr, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i, wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, y0r, y0i, y2r, y2i;
    
    mh = n >> 3;
    m = 2 * mh;
    wn4r = w[1];
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] - a[j2 + 1];
    x0i = a[1] + a[j2];
    x1r = a[0] + a[j2 + 1];
    x1i = a[1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wn4r * (x2r - x2i);
    y0i = wn4r * (x2i + x2r);
    a[0] = x0r + y0r;
    a[1] = x0i + y0i;
    a[j1] = x0r - y0r;
    a[j1 + 1] = x0i - y0i;
    y0r = wn4r * (x3r - x3i);
    y0i = wn4r * (x3i + x3r);
    a[j2] = x1r - y0i;
    a[j2 + 1] = x1i + y0r;
    a[j3] = x1r + y0i;
    a[j3 + 1] = x1i - y0r;
    k = 0;
    kr = 2 * m;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        kr -= 4;
        wd1i = w[kr];
        wd1r = w[kr + 1];
        wd3i = w[kr + 2];
        wd3r = w[kr + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] - a[j2 + 1];
        x0i = a[j + 1] + a[j2];
        x1r = a[j] + a[j2 + 1];
        x1i = a[j + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wk1r * x0r - wk1i * x0i;
        y0i = wk1r * x0i + wk1i * x0r;
        y2r = wd1r * x2r - wd1i * x2i;
        y2i = wd1r * x2i + wd1i * x2r;
        a[j] = y0r + y2r;
        a[j + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wk3r * x1r + wk3i * x1i;
        y0i = wk3r * x1i - wk3i * x1r;
        y2r = wd3r * x3r + wd3i * x3i;
        y2i = wd3r * x3i - wd3i * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] - a[j2 + 1];
        x0i = a[j0 + 1] + a[j2];
        x1r = a[j0] + a[j2 + 1];
        x1i = a[j0 + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wd1i * x0r - wd1r * x0i;
        y0i = wd1i * x0i + wd1r * x0r;
        y2r = wk1i * x2r - wk1r * x2i;
        y2i = wk1i * x2i + wk1r * x2r;
        a[j0] = y0r + y2r;
        a[j0 + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wd3i * x1r + wd3r * x1i;
        y0i = wd3i * x1i - wd3r * x1r;
        y2r = wk3i * x3r + wk3r * x3i;
        y2i = wk3i * x3i - wk3r * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
    }
    wk1r = w[m];
    wk1i = w[m + 1];
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] - a[j2 + 1];
    x0i = a[j0 + 1] + a[j2];
    x1r = a[j0] + a[j2 + 1];
    x1i = a[j0 + 1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wk1r * x0r - wk1i * x0i;
    y0i = wk1r * x0i + wk1i * x0r;
    y2r = wk1i * x2r - wk1r * x2i;
    y2i = wk1i * x2i + wk1r * x2r;
    a[j0] = y0r + y2r;
    a[j0 + 1] = y0i + y2i;
    a[j1] = y0r - y2r;
    a[j1 + 1] = y0i - y2i;
    y0r = wk1i * x1r - wk1r * x1i;
    y0i = wk1i * x1i + wk1r * x1r;
    y2r = wk1r * x3r - wk1i * x3i;
    y2i = wk1r * x3i + wk1i * x3r;
    a[j2] = y0r - y2r;
    a[j2 + 1] = y0i - y2i;
    a[j3] = y0r + y2r;
    a[j3 + 1] = y0i + y2i;
}

static int cfttree(int n, int j, int k, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    int i, isplt, m;
    
    if ((k & 3) != 0) {
        isplt = k & 1;
        if (isplt != 0) {
            cftmdl1(n, &a[j - n], &w[nw - (n >> 1)]);
        } else {
            cftmdl2(n, &a[j - n], &w[nw - n]);
        }
    } else {
        m = n;
        for (i = k; (i & 3) == 0; i >>= 2) {
            m <<= 2;
        }
        isplt = i & 1;
        if (isplt != 0) {
            while (m > 128) {
                cftmdl1(m, &a[j - m], &w[nw - (m >> 1)]);
                m >>= 2;
            }
        } else {
            while (m > 128) {
                cftmdl2(m, &a[j - m], &w[nw - m]);
                m >>= 2;
            }
        }
    }
    return isplt;
}

static void cftf161(float *a, float *w)
{
    float wn4r, wk1r, wk1i, 
        x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    x0r = a[0] + a[16];
    x0i = a[1] + a[17];
    x1r = a[0] - a[16];
    x1i = a[1] - a[17];
    x2r = a[8] + a[24];
    x2i = a[9] + a[25];
    x3r = a[8] - a[24];
    x3i = a[9] - a[25];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y4r = x0r - x2r;
    y4i = x0i - x2i;
    y8r = x1r - x3i;
    y8i = x1i + x3r;
    y12r = x1r + x3i;
    y12i = x1i - x3r;
    x0r = a[2] + a[18];
    x0i = a[3] + a[19];
    x1r = a[2] - a[18];
    x1i = a[3] - a[19];
    x2r = a[10] + a[26];
    x2i = a[11] + a[27];
    x3r = a[10] - a[26];
    x3i = a[11] - a[27];
    y1r = x0r + x2r;
    y1i = x0i + x2i;
    y5r = x0r - x2r;
    y5i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y9r = wk1r * x0r - wk1i * x0i;
    y9i = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y13r = wk1i * x0r - wk1r * x0i;
    y13i = wk1i * x0i + wk1r * x0r;
    x0r = a[4] + a[20];
    x0i = a[5] + a[21];
    x1r = a[4] - a[20];
    x1i = a[5] - a[21];
    x2r = a[12] + a[28];
    x2i = a[13] + a[29];
    x3r = a[12] - a[28];
    x3i = a[13] - a[29];
    y2r = x0r + x2r;
    y2i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y10r = wn4r * (x0r - x0i);
    y10i = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y14r = wn4r * (x0r + x0i);
    y14i = wn4r * (x0i - x0r);
    x0r = a[6] + a[22];
    x0i = a[7] + a[23];
    x1r = a[6] - a[22];
    x1i = a[7] - a[23];
    x2r = a[14] + a[30];
    x2i = a[15] + a[31];
    x3r = a[14] - a[30];
    x3i = a[15] - a[31];
    y3r = x0r + x2r;
    y3i = x0i + x2i;
    y7r = x0r - x2r;
    y7i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y11r = wk1i * x0r - wk1r * x0i;
    y11i = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y15r = wk1r * x0r - wk1i * x0i;
    y15i = wk1r * x0i + wk1i * x0r;
    x0r = y12r - y14r;
    x0i = y12i - y14i;
    x1r = y12r + y14r;
    x1i = y12i + y14i;
    x2r = y13r - y15r;
    x2i = y13i - y15i;
    x3r = y13r + y15r;
    x3i = y13i + y15i;
    a[24] = x0r + x2r;
    a[25] = x0i + x2i;
    a[26] = x0r - x2r;
    a[27] = x0i - x2i;
    a[28] = x1r - x3i;
    a[29] = x1i + x3r;
    a[30] = x1r + x3i;
    a[31] = x1i - x3r;
    x0r = y8r + y10r;
    x0i = y8i + y10i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    x3r = y9r - y11r;
    x3i = y9i - y11i;
    a[16] = x0r + x2r;
    a[17] = x0i + x2i;
    a[18] = x0r - x2r;
    a[19] = x0i - x2i;
    a[20] = x1r - x3i;
    a[21] = x1i + x3r;
    a[22] = x1r + x3i;
    a[23] = x1i - x3r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x3r = wn4r * (x0r - x0i);
    x3i = wn4r * (x0i + x0r);
    x0r = y4r - y6i;
    x0i = y4i + y6r;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    a[8] = x0r + x2r;
    a[9] = x0i + x2i;
    a[10] = x0r - x2r;
    a[11] = x0i - x2i;
    a[12] = x1r - x3i;
    a[13] = x1i + x3r;
    a[14] = x1r + x3i;
    a[15] = x1i - x3r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    x3r = y1r - y3r;
    x3i = y1i - y3i;
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x0r - x2r;
    a[3] = x0i - x2i;
    a[4] = x1r - x3i;
    a[5] = x1i + x3r;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftf162(float *a, float *w)
{
    float wn4r, wk1r, wk1i, wk2r, wk2i, wk3r, wk3i, 
        x0r, x0i, x1r, x1i, x2r, x2i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[4];
    wk1i = w[5];
    wk3r = w[6];
    wk3i = -w[7];
    wk2r = w[8];
    wk2i = w[9];
    x1r = a[0] - a[17];
    x1i = a[1] + a[16];
    x0r = a[8] - a[25];
    x0i = a[9] + a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y0r = x1r + x2r;
    y0i = x1i + x2i;
    y4r = x1r - x2r;
    y4i = x1i - x2i;
    x1r = a[0] + a[17];
    x1i = a[1] - a[16];
    x0r = a[8] + a[25];
    x0i = a[9] - a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y8r = x1r - x2i;
    y8i = x1i + x2r;
    y12r = x1r + x2i;
    y12i = x1i - x2r;
    x0r = a[2] - a[19];
    x0i = a[3] + a[18];
    x1r = wk1r * x0r - wk1i * x0i;
    x1i = wk1r * x0i + wk1i * x0r;
    x0r = a[10] - a[27];
    x0i = a[11] + a[26];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y1r = x1r + x2r;
    y1i = x1i + x2i;
    y5r = x1r - x2r;
    y5i = x1i - x2i;
    x0r = a[2] + a[19];
    x0i = a[3] - a[18];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[10] + a[27];
    x0i = a[11] - a[26];
    x2r = wk1r * x0r + wk1i * x0i;
    x2i = wk1r * x0i - wk1i * x0r;
    y9r = x1r - x2r;
    y9i = x1i - x2i;
    y13r = x1r + x2r;
    y13i = x1i + x2i;
    x0r = a[4] - a[21];
    x0i = a[5] + a[20];
    x1r = wk2r * x0r - wk2i * x0i;
    x1i = wk2r * x0i + wk2i * x0r;
    x0r = a[12] - a[29];
    x0i = a[13] + a[28];
    x2r = wk2i * x0r - wk2r * x0i;
    x2i = wk2i * x0i + wk2r * x0r;
    y2r = x1r + x2r;
    y2i = x1i + x2i;
    y6r = x1r - x2r;
    y6i = x1i - x2i;
    x0r = a[4] + a[21];
    x0i = a[5] - a[20];
    x1r = wk2i * x0r - wk2r * x0i;
    x1i = wk2i * x0i + wk2r * x0r;
    x0r = a[12] + a[29];
    x0i = a[13] - a[28];
    x2r = wk2r * x0r - wk2i * x0i;
    x2i = wk2r * x0i + wk2i * x0r;
    y10r = x1r - x2r;
    y10i = x1i - x2i;
    y14r = x1r + x2r;
    y14i = x1i + x2i;
    x0r = a[6] - a[23];
    x0i = a[7] + a[22];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[14] - a[31];
    x0i = a[15] + a[30];
    x2r = wk1i * x0r - wk1r * x0i;
    x2i = wk1i * x0i + wk1r * x0r;
    y3r = x1r + x2r;
    y3i = x1i + x2i;
    y7r = x1r - x2r;
    y7i = x1i - x2i;
    x0r = a[6] + a[23];
    x0i = a[7] - a[22];
    x1r = wk1i * x0r + wk1r * x0i;
    x1i = wk1i * x0i - wk1r * x0r;
    x0r = a[14] + a[31];
    x0i = a[15] - a[30];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y11r = x1r + x2r;
    y11i = x1i + x2i;
    y15r = x1r - x2r;
    y15i = x1i - x2i;
    x1r = y0r + y2r;
    x1i = y0i + y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    a[0] = x1r + x2r;
    a[1] = x1i + x2i;
    a[2] = x1r - x2r;
    a[3] = x1i - x2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r - y3r;
    x2i = y1i - y3i;
    a[4] = x1r - x2i;
    a[5] = x1i + x2r;
    a[6] = x1r + x2i;
    a[7] = x1i - x2r;
    x1r = y4r - y6i;
    x1i = y4i + y6r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[8] = x1r + x2r;
    a[9] = x1i + x2i;
    a[10] = x1r - x2r;
    a[11] = x1i - x2i;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[12] = x1r - x2i;
    a[13] = x1i + x2r;
    a[14] = x1r + x2i;
    a[15] = x1i - x2r;
    x1r = y8r + y10r;
    x1i = y8i + y10i;
    x2r = y9r - y11r;
    x2i = y9i - y11i;
    a[16] = x1r + x2r;
    a[17] = x1i + x2i;
    a[18] = x1r - x2r;
    a[19] = x1i - x2i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    a[20] = x1r - x2i;
    a[21] = x1i + x2r;
    a[22] = x1r + x2i;
    a[23] = x1i - x2r;
    x1r = y12r - y14i;
    x1i = y12i + y14r;
    x0r = y13r + y15i;
    x0i = y13i - y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[24] = x1r + x2r;
    a[25] = x1i + x2i;
    a[26] = x1r - x2r;
    a[27] = x1i - x2i;
    x1r = y12r + y14i;
    x1i = y12i - y14r;
    x0r = y13r - y15i;
    x0i = y13i + y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[28] = x1r - x2i;
    a[29] = x1i + x2r;
    a[30] = x1r + x2i;
    a[31] = x1i - x2r;
}

static void cftf081(float *a, float *w)
{
    float wn4r, x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    x0r = a[0] + a[8];
    x0i = a[1] + a[9];
    x1r = a[0] - a[8];
    x1i = a[1] - a[9];
    x2r = a[4] + a[12];
    x2i = a[5] + a[13];
    x3r = a[4] - a[12];
    x3i = a[5] - a[13];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y2r = x0r - x2r;
    y2i = x0i - x2i;
    y1r = x1r - x3i;
    y1i = x1i + x3r;
    y3r = x1r + x3i;
    y3i = x1i - x3r;
    x0r = a[2] + a[10];
    x0i = a[3] + a[11];
    x1r = a[2] - a[10];
    x1i = a[3] - a[11];
    x2r = a[6] + a[14];
    x2i = a[7] + a[15];
    x3r = a[6] - a[14];
    x3i = a[7] - a[15];
    y4r = x0r + x2r;
    y4i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    x2r = x1r + x3i;
    x2i = x1i - x3r;
    y5r = wn4r * (x0r - x0i);
    y5i = wn4r * (x0r + x0i);
    y7r = wn4r * (x2r - x2i);
    y7i = wn4r * (x2r + x2i);
    a[8] = y1r + y5r;
    a[9] = y1i + y5i;
    a[10] = y1r - y5r;
    a[11] = y1i - y5i;
    a[12] = y3r - y7i;
    a[13] = y3i + y7r;
    a[14] = y3r + y7i;
    a[15] = y3i - y7r;
    a[0] = y0r + y4r;
    a[1] = y0i + y4i;
    a[2] = y0r - y4r;
    a[3] = y0i - y4i;
    a[4] = y2r - y6i;
    a[5] = y2i + y6r;
    a[6] = y2r + y6i;
    a[7] = y2i - y6r;
}

static void cftf082(float *a, float *w)
{
    float wn4r, wk1r, wk1i, x0r, x0i, x1r, x1i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    y0r = a[0] - a[9];
    y0i = a[1] + a[8];
    y1r = a[0] + a[9];
    y1i = a[1] - a[8];
    x0r = a[4] - a[13];
    x0i = a[5] + a[12];
    y2r = wn4r * (x0r - x0i);
    y2i = wn4r * (x0i + x0r);
    x0r = a[4] + a[13];
    x0i = a[5] - a[12];
    y3r = wn4r * (x0r - x0i);
    y3i = wn4r * (x0i + x0r);
    x0r = a[2] - a[11];
    x0i = a[3] + a[10];
    y4r = wk1r * x0r - wk1i * x0i;
    y4i = wk1r * x0i + wk1i * x0r;
    x0r = a[2] + a[11];
    x0i = a[3] - a[10];
    y5r = wk1i * x0r - wk1r * x0i;
    y5i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] - a[15];
    x0i = a[7] + a[14];
    y6r = wk1i * x0r - wk1r * x0i;
    y6i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] + a[15];
    x0i = a[7] - a[14];
    y7r = wk1r * x0r - wk1i * x0i;
    y7i = wk1r * x0i + wk1i * x0r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y4r + y6r;
    x1i = y4i + y6i;
    a[0] = x0r + x1r;
    a[1] = x0i + x1i;
    a[2] = x0r - x1r;
    a[3] = x0i - x1i;
    x0r = y0r - y2r;
    x0i = y0i - y2i;
    x1r = y4r - y6r;
    x1i = y4i - y6i;
    a[4] = x0r - x1i;
    a[5] = x0i + x1r;
    a[6] = x0r + x1i;
    a[7] = x0i - x1r;
    x0r = y1r - y3i;
    x0i = y1i + y3r;
    x1r = y5r - y7r;
    x1i = y5i - y7i;
    a[8] = x0r + x1r;
    a[9] = x0i + x1i;
    a[10] = x0r - x1r;
    a[11] = x0i - x1i;
    x0r = y1r + y3i;
    x0i = y1i - y3r;
    x1r = y5r + y7r;
    x1i = y5i + y7i;
    a[12] = x0r - x1i;
    a[13] = x0i + x1r;
    a[14] = x0r + x1i;
    a[15] = x0i - x1r;
}

static void cftleaf(int n, int isplt, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 512) {
        cftmdl1(128, a, &w[nw - 64]);
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
        cftmdl2(128, &a[128], &w[nw - 128]);
        cftf161(&a[128], &w[nw - 8]);
        cftf162(&a[160], &w[nw - 32]);
        cftf161(&a[192], &w[nw - 8]);
        cftf162(&a[224], &w[nw - 32]);
        cftmdl1(128, &a[256], &w[nw - 64]);
        cftf161(&a[256], &w[nw - 8]);
        cftf162(&a[288], &w[nw - 32]);
        cftf161(&a[320], &w[nw - 8]);
        cftf161(&a[352], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(128, &a[384], &w[nw - 64]);
            cftf161(&a[480], &w[nw - 8]);
        } else {
            cftmdl2(128, &a[384], &w[nw - 128]);
            cftf162(&a[480], &w[nw - 32]);
        }
        cftf161(&a[384], &w[nw - 8]);
        cftf162(&a[416], &w[nw - 32]);
        cftf161(&a[448], &w[nw - 8]);
    } else {
        cftmdl1(64, a, &w[nw - 32]);
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
        cftmdl2(64, &a[64], &w[nw - 64]);
        cftf081(&a[64], &w[nw - 8]);
        cftf082(&a[80], &w[nw - 8]);
        cftf081(&a[96], &w[nw - 8]);
        cftf082(&a[112], &w[nw - 8]);
        cftmdl1(64, &a[128], &w[nw - 32]);
        cftf081(&a[128], &w[nw - 8]);
        cftf082(&a[144], &w[nw - 8]);
        cftf081(&a[160], &w[nw - 8]);
        cftf081(&a[176], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(64, &a[192], &w[nw - 32]);
            cftf081(&a[240], &w[nw - 8]);
        } else {
            cftmdl2(64, &a[192], &w[nw - 64]);
            cftf082(&a[240], &w[nw - 8]);
        }
        cftf081(&a[192], &w[nw - 8]);
        cftf082(&a[208], &w[nw - 8]);
        cftf081(&a[224], &w[nw - 8]);
    }
}

static void cftrec4(int n, float *a, int nw, float *w)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m;
    
    m = n;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
}

static void cftfx41(int n, float *a, int nw, float *w)
{
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 128) {
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
    } else {
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
    }
}

static void cftf040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r - x3i;
    a[3] = x1i + x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftx020(float *a)
{
    float x0r, x0i;
    
    x0r = a[0] - a[2];
    x0i = a[1] - a[3];
    a[0] += a[2];
    a[1] += a[3];
    a[2] = x0r;
    a[3] = x0i;
}

#ifdef USE_CDFT_THREADS
struct cdft_arg_st {
    int n0;
    int n;
    float *a;
    int nw;
    float *w;
};
typedef struct cdft_arg_st cdft_arg_t;


static void cftrec4_th(int n, float *a, int nw, float *w)
{
    void *cftrec1_th(void *p);
    void *cftrec2_th(void *p);
    int i, idiv4, m, nthread;
    cdft_thread_t th[4];
    cdft_arg_t ag[4];
    
    nthread = 2;
    idiv4 = 0;
    m = n >> 1;
    if (n > CDFT_4THREADS_BEGIN_N) {
        nthread = 4;
        idiv4 = 1;
        m >>= 1;
    }
    for (i = 0; i < nthread; i++) {
        ag[i].n0 = n;
        ag[i].n = m;
        ag[i].a = &a[i * m];
        ag[i].nw = nw;
        ag[i].w = w;
        if (i != idiv4) {
            cdft_thread_create(&th[i], cftrec1_th, &ag[i]);
        } else {
            cdft_thread_create(&th[i], cftrec2_th, &ag[i]);
        }
    }
    for (i = 0; i < nthread; i++) {
        cdft_thread_wait(th[i]);
    }
}


static void *cftrec1_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    m = n0;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}


static void *cftrec2_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl2(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    k = 1;
    m = n0;
    while (m > 512) {
        m >>= 2;
        k <<= 2;
        cftmdl2(m, &a[n - m], &w[nw - m]);
    }
    cftleaf(m, 0, &a[n - m], nw, w);
    k >>= 1;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}
#endif /* USE_CDFT_THREADS */

static void cftfsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2(int n, int *ip, float *a);
    void bitrv216(float *a);
    void bitrv208(float *a);
    void cftf1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftf1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216(a);
        } else {
            cftf081(a, w);
            bitrv208(a);
        }
    } else if (n == 8) {
        cftf040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void bitrv2conj(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += nm;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    }
}

static void bitrv216neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i, x8r, x8i, 
        x9r, x9i, x10r, x10i, x11r, x11i, x12r, x12i, 
        x13r, x13i, x14r, x14i, x15r, x15i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x9r = a[18];
    x9i = a[19];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    x15r = a[30];
    x15i = a[31];
    a[2] = x15r;
    a[3] = x15i;
    a[4] = x7r;
    a[5] = x7i;
    a[6] = x11r;
    a[7] = x11i;
    a[8] = x3r;
    a[9] = x3i;
    a[10] = x13r;
    a[11] = x13i;
    a[12] = x5r;
    a[13] = x5i;
    a[14] = x9r;
    a[15] = x9i;
    a[16] = x1r;
    a[17] = x1i;
    a[18] = x14r;
    a[19] = x14i;
    a[20] = x6r;
    a[21] = x6i;
    a[22] = x10r;
    a[23] = x10i;
    a[24] = x2r;
    a[25] = x2i;
    a[26] = x12r;
    a[27] = x12i;
    a[28] = x4r;
    a[29] = x4i;
    a[30] = x8r;
    a[31] = x8i;
}

static void bitrv208neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    a[2] = x7r;
    a[3] = x7i;
    a[4] = x3r;
    a[5] = x3i;
    a[6] = x5r;
    a[7] = x5i;
    a[8] = x1r;
    a[9] = x1i;
    a[10] = x6r;
    a[11] = x6i;
    a[12] = x2r;
    a[13] = x2i;
    a[14] = x4r;
    a[15] = x4i;
}

static void cftb1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = -a[1] - a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = -a[1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    a[j2] = x1r + x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r - x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = -a[j + 1] - a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = -a[j + 1] + a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = -a[j + 3] - a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = -a[j + 3] + a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i - x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = -a[j0 + 1] - a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = -a[j0 + 1] + a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = -a[j0 - 1] - a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = -a[j0 - 1] + a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i - x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = -a[j0 - 1] - a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = -a[j0 - 1] + a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i - x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = -a[j0 + 1] - a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = -a[j0 + 1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = -a[j0 + 3] - a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = -a[j0 + 3] + a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i - x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftb040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r + x3i;
    a[3] = x1i - x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r - x3i;
    a[7] = x1i + x3r;
}

static void cftbsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2conj(int n, int *ip, float *a);
    void bitrv216neg(float *a);
    void bitrv208neg(float *a);
    void cftb1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftb040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftb1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2conj(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216neg(a);
        } else {
            cftf081(a, w);
            bitrv208neg(a);
        }
    } else if (n == 8) {
        cftb040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void rftfsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr - wki * xi;
        yi = wkr * xi + wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rftbsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr + wki * xi;
        yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rdft(int n, int isgn, float *a, int *ip, float *w)
{
    void makewt(int nw, int *ip, float *w);
    void makect(int nc, int *ip, float *c);
    void cftfsub(int n, float *a, int *ip, int nw, float *w);
    void cftbsub(int n, float *a, int *ip, int nw, float *w);
    void rftfsub(int n, float *a, int nc, float *c);
    void rftbsub(int n, float *a, int nc, float *c);
    int nw, nc;
    float xi;
    
    nw = ip[0];
    if (n > (nw << 2)) {
        nw = n >> 2;
        makewt(nw, ip, w);
    }
    nc = ip[1];
    if (n > (nc << 2)) {
        nc = n >> 2;
        makect(nc, ip, w + nw);
    }
    if (isgn >= 0) {
        if (n > 4) {
            cftfsub(n, a, ip, nw, w);
            rftfsub(n, a, nc, w + nw);
        } else if (n == 4) {
            cftfsub(n, a, ip, nw, w);
        }
        xi = a[0] - a[1];
        a[0] += a[1];
        a[1] = xi;
    } else {
        a[1] = 0.5 * (a[0] - a[1]);
        a[0] -= a[1];
        if (n > 4) {
            rftbsub(n, a, nc, w + nw);
            cftbsub(n, a, ip, nw, w);
        } else if (n == 4) {
            cftbsub(n, a, ip, nw, w);
        }
    }
}

// input array (any shape >= 1D)
// output array (shape = input.shape.replace(axis, n).insert(0,2))
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void rfft_libfft_f32(
    const float* restrict input, 
    float* restrict output, 
    int d0, int d1, int d2,
    int32_t* restrict temp_ip, float* restrict temp_w, float* restrict temp_a)
{
    void rdft(int n, int isgn, float* a, int* ip, float* w);

    int d3 = d0 * d1;
    int d_out = (d1 >> 1) + 1;

    for (int k = 0; k < d2; k++)
    {
        int dk = k * d3;
        int dm = k * 2 * d_out * d0;
        for (int i = 0; i < d0; i++)
        {                	           
            for (int j = 0; j < d1; j++)
            {
                temp_a[j] = input[dk + j * d0 + i];
            }
            rdft(d1, 1, temp_a, (int *)temp_ip, temp_w);

            for (int m = 2; m < d1; m+=2)
            {
                int index = (m * d0) + 2 * i + dm;
                output[index] = temp_a[m];
                output[index + 1] = -temp_a[m + 1];
            }
            int beta = dm + 2 * i;
            output[beta] = temp_a[0];
            output[beta + 1] = 0;
            output[beta + d3] = temp_a[1];
            output[beta + d3 + 1] = 0;
        }
    }
}

static inline float __norm_sqrt_sum_f32(const float* restrict input, int count)
{
	float sum = 0;
	for (int j = 0; j < count; j++) {
		float item = *input++;
		sum += item * item;
	}
	return sqrtf(sum);
}

static inline void norm_f32(const float* restrict input, int d1, int d2, float* restrict output)
{
	for (int k = 0; k < d2; k++) {
		*output++ = __norm_sqrt_sum_f32(input, d1);
		input += d1;
	}
}

static inline float __mel_f32(const float* restrict input, const short* restrict filter_points, int filter)
{
	short n0 = filter_points[filter];
	short n1 = filter_points[filter+1];
	short n2 = filter_points[filter+2];
	short c0 = n1 - n0;
	short c1 = n2 - n1;
	float sum = 0;
	
	for (int i = 0; i <= c0; i++) {
		float rate = i / (float)c0;
		float value = input[i + n0];
		sum += value * rate;
	}

	for (int i = 1; i <= c1; i++) {
		float rate = i / (float)c1;
		float value = input[i + n1];
		sum += value * (1.0 - rate);
	}

	return sum;
}

// input array (any shape >= 1D)
// output array (same shape as input array except with 0 replaced with num_filter)
// size = input.shape.size(0)
// slot = input.shape.slot(0)
static inline void mel_f32(const float* restrict input, const short* restrict filter_points, int size, int slot, int num_filter, float* restrict output)
{	
	for (int k = 0; k < slot; k++) {
		const float *ip = input + k * size;
		for (int i = 0; i < num_filter; i++) {
			*output++ = __mel_f32(ip, filter_points, i);
		}
	}
}

static inline void addi_f32(
	const float* restrict x,
	int count,
	float immediate,
	float* restrict output)
{
	for (int i = 0; i < count; i++) {
		output[i] = x[i] + immediate;
	}
}

static inline void ln_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		*result++ = logf(*x++);
	}
}

static inline void clip_f32(const float* restrict input, int count, float min, float max, float* restrict output)
{	
	for (int i = 0; i < count; i++) {
		float value = input[i];
		if (value > max)
			value = max;
		if (value < min)
			value = min;

		output[i] = value;
	}
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_ERROR (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueue(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

static inline void mtb_model_f32(const void* handle, const float* restrict src, int src_count, float* restrict dst, int dst_count)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_run(model, (float*)src);
	memcpy(dst, model->output, dst_count * sizeof(float));
}

static inline void mtb_model_free(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_deinit(model);
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param count Number of items (of size input_size) in each window
*/
static inline void fixwin_init(void* restrict handle, int input_size, int count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

int mtb_init(const void *handle, uint8_t* model_bin, unsigned int model_size, uint8_t* arena_buffer, int arena_size) {
	
	mtb_ml_model_t** model_obj = (mtb_ml_model_t**)handle;
	
	mtb_ml_model_bin_t model = { "model", model_bin, model_size, arena_size };
	mtb_ml_model_buffer_t buffer = { arena_buffer, arena_size };
	if (mtb_ml_model_init(&model, &buffer, model_obj) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

	return 0;
}

#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) return __ret; } while(0)
#define __RETURN_ALWAYS(_exp) return (_exp)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) return __ret; }
#define __RETURN_ERROR_BREAK_EMPTY_END(_exp) {  int __ret = (_exp); if(__ret == -1 || __ret == -3) break; if(__ret < 0) return __ret; }
#define __RETURN_ERROR_CANCEL_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) return 0; if(__ret < 0) return __ret; }
#define __BREAK_ERROR(_exp) {  int __ret = (_exp); if(__ret < 0) break; }

/*
* Try read data from model.
* 
*  @param data_out Output features. Output float[4].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_dequeue(float *restrict data_out) {    
    while(1) {
        __RETURN_ERROR_BREAK_EMPTY(fixwin_dequeue(_K2, _K1, 512, 160));
        hammingmul_f32(_K1, _K11, 1, 512, 1, _K15);
        rfft_libfft_f32(_K15, _K16, 1, 512, 1, _K18, _K19, _K20);
        norm_f32(_K16, 2, 257, _K22);
        mel_f32(_K22, _K23, 257, 1, 40, _K27);
        addi_f32(_K27, 40, 1, _K28);
        ln_f32(_K28, 40, _K29);
        clip_f32(_K29, 40, 0, 4, _K3);
        __RETURN_ERROR_BREAK_EMPTY(fixwin_enqueue(_K5, _K3));
    }
    __RETURN_ERROR(fixwin_dequeue(_K5, _K4, 300, 10));
    mtb_model_f32(_K10, _K4, 12000, data_out, 4);
    return 0;
}

/*
* Try write data to model.
* 
*  @param data_in Input features. Input float[1].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_enqueue(const float *restrict data_in) {    
    __RETURN_ERROR(fixwin_enqueue(_K2, data_in));
    return 0;
}

/*
* Closes and flushes streams, free any heap allocated memory.
* 
*/
void IMAI_finalize(void) {    
    mtb_model_free(_K10);
}

/*
* Initializes buffers to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_init(void) {    
    fixwin_init(_K2, 4, 512);
    fixwin_init(_K5, 160, 300);
    __RETURN_ERROR(mtb_init(_K10, _K7, 33784, _K6, 107520));
    return 0;
}

#ifdef IMAI_REFLECTION

static IMAI_api_def _IMAI_api_def = {
    api_ver: 1,
    id: {0x9c, 0x7a, 0xfd, 0x23, 0x55, 0x8d, 0x5e, 0x43, 0x96, 0xf5, 0x35, 0xa4, 0xf1, 0x21, 0xfd, 0x03},
    api_type: IMAI_API_TYPE_QUEUE,
    prefix: "IMAI_",
    buffer_mem: {
        size: 48000,
        peak_usage: 48000,
    },
    static_mem: {
        size: 159120,
        peak_usage: 159120,
    },
    readonly_mem: {
        size: 35916,
        peak_usage: 35916,
    },
    func_count: 4,
    func_list: (IMAI_func_def[]) {
        {
            name: "IMAI_dequeue",
            description: "Try read data from model.",
            fn_ptr: IMAI_dequeue,
            attrib: 3,
            param_count: 1,
            param_list: (IMAI_param_def[]) {
                {
                    name: "data_out",
                    attrib: IMAI_PARAM_OUTPUT,
                    rank: 1,
                    shape: (IMAI_shape_dim[]) {
                        {
                            name: "Labels",
                            size: 4,
                            labels: (label_text_t[]) { "unlabelled","Chainsaw","Standby","Human" },
                        },
                    },
                    count: 4,
                    type_id: IMAGINET_TYPES_FLOAT32,
                    frequency: 10,
                    shift: 3,
                    scale: 1,
                    offset: 0,
                },
            },
        },
        {
            name: "IMAI_enqueue",
            description: "Try write data to model.",
            fn_ptr: IMAI_enqueue,
            attrib: 3,
            param_count: 1,
            param_list: (IMAI_param_def[]) {
                {
                    name: "data_in",
                    attrib: IMAI_PARAM_INPUT,
                    rank: 1,
                    shape: (IMAI_shape_dim[]) {
                        {
                            name: "",
                            size: 1,
                        },
                    },
                    count: 1,
                    type_id: IMAGINET_TYPES_FLOAT32,
                    frequency: 16000,
                    shift: 0,
                    scale: 1,
                    offset: 0,
                },
            },
        },
        {
            name: "IMAI_finalize",
            description: "Closes and flushes streams, free any heap allocated memory.",
            fn_ptr: IMAI_finalize,
            attrib: 10,
            param_count: 0,
            param_list: (IMAI_param_def[]) {
            },
        },
        {
            name: "IMAI_init",
            description: "Initializes buffers to initial state.",
            fn_ptr: IMAI_init,
            attrib: 7,
            param_count: 0,
            param_list: (IMAI_param_def[]) {
            },
        },
    },
};

IMAI_api_def *IMAI_api(void) {
    return &_IMAI_api_def;
}

#endif /* IMAI_REFLECTION */

