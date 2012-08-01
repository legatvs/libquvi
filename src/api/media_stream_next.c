/* libquvi
 * Copyright (C) 2012  Toni Gundogdu <legatvs@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/** @file media_stream_next.c */

#include "config.h"

#include <glib.h>

#include "quvi.h"
/* -- */
#include "_quvi_s.h"
#include "_quvi_media_s.h"

/** @brief Traverse to next available @ref m_stream
@return QUVI_TRUE if succeeded, otherwise QUVI_FALSE
@sa @ref parse_media
@ingroup mediaprop
*/
QuviBoolean quvi_media_stream_next(quvi_media_t handle)
{
  _quvi_media_t qm = (_quvi_media_t) handle;

  /* If G_DISABLE_CHECKS is defined then the check is not performed. */
  g_return_val_if_fail(handle != NULL, QUVI_FALSE);

  qm->curr.stream = (qm->curr.stream != NULL)
                    ? g_slist_next(qm->curr.stream)
                    : qm->streams;

  return ((qm->curr.stream != NULL)
          ? QUVI_TRUE
          : QUVI_FALSE);
}

/* vim: set ts=2 sw=2 tw=72 expandtab: */
