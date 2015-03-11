// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LEVELDB_COMPRESS_BMZ_LITE_H
#define LEVELDB_COMPRESS_BMZ_LITE_H

#include <stdlib.h>
#include <stdint.h>

#define BMZ_E_OK    (0)
#define BMZ_E_ERROR (-1)
#define BMZ_E_INPUT_OVERRUN   (-4)
#define BMZ_E_OUTPUT_OVERRUN  (-5)
#define BMZ_E_ERROR_FORMAT    (-6)

namespace bmz {

/**
 * @brief bmz��ʼ������Ҫ��ʼ��lzo
 *
 * @return �ɹ�����BMZ_E_OK
 */

int bmz_init();

/**
 * @brief ����bmz��������Ҫ�����ڴ��С
 *
 * @param in_len ���볤��
 * @param fp_len ̽�볤��
 *
 * @return �����ڴ泤��
 */

size_t bmz_pack_worklen(size_t in_len, size_t fp_len);

/**
 * @brief ����bmz��������Ҫ�����ڴ��С
 *
 * @param in_len �������
 *
 * @return �����ڴ泤��
 */

size_t bmz_unpack_worklen(size_t out_len);

/**
 * @brief bmz����
 *
 * @param in Դ��ַ
 * @param in_len Դ����
 * @param out Ŀ���ַ
 * @param out_len_p Ŀ�곤��ָ��
 * @param fp_len ̽�볤��
 * @param work_mem �����ڴ�,�ڴ��Сͨ��bmz_pack_worklen����
 *
 * @return �ɹ�����BMZ_E_OK��ʧ�ܷ�����Ӧ�Ĵ�����
 */

int bmz_pack(const void *in,  size_t in_len, void *out, size_t *out_len_p, size_t	fp_len, void *work_mem);

/**
 * @brief bmz����
 *
 * @param in Դ��ַ
 * @param in_len Դ����
 * @param out Ŀ���ַ
 * @param out_len_p Ŀ�곤��ָ��
 * @param work_mem �����ڴ棬�ڴ��Сͨ��bmz_unpack_worklen����
 *
 * @return �ɹ�����BMZ_E_OK,ʧ�ܷ�����صĴ�����
 */

int bmz_unpack(const void *in, size_t in_len, void *out, size_t	*out_len_p,  void *work_mem);

} // namespace bmz

#endif ///LEVELDB_COMPRESS_BMZ_LITE_H