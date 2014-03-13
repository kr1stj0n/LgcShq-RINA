/*
 * DT (Data Transfer)
 *
 *    Francesco Salvestrini <f.salvestrini@nextworks.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef RINA_DT_H
#define RINA_DT_H

#include "common.h"

struct dtp;
struct dtcp;
struct dt;

/*
 * FIXME: The DT instance would represent the DTP/DTCP couple. It has to land
 *        on EFCP. DTP, DTCP instances have to be removed from there
 */
struct dt *   dt_create(void);
int           dt_destroy(struct dt * dt);

int           dt_dtp_bind(struct dt *  dt, struct dtp *  dtp);
struct dtp *  dt_dtp_unbind(struct dt *  dt);

int           dt_dtcp_bind(struct dt * dt, struct dtcp * dtp);
struct dtcp * dt_dtcp_unbind(struct dt * dt);

struct dtp *  dt_dtp(struct dt * dt);
struct dtcp * dt_dtcp(struct dt * dt);

struct cwq *  dt_cwq(struct dt * dt);
struct rtxq * dt_rtxq(struct dt * dt);

/* Accessors to the DT state vector */
uint_t        dt_sv_max_pdu_size(struct dt * dt);
uint_t        dt_sv_max_sdu_size(struct dt * dt);
seq_num_t     dt_sv_rcv_lft_win(struct dt * dt);
int           dt_sv_rcv_lft_win_set(struct dt * dt, seq_num_t rcv_lft_win);
timeout_t     dt_sv_mpl(struct dt * dt);
timeout_t     dt_sv_r(struct dt * dt);
timeout_t     dt_sv_a(struct dt * dt);
bool          dt_sv_window_closed(struct dt * dt);
int           dt_sv_window_closed_set(struct dt * dt, bool closed);

#endif
