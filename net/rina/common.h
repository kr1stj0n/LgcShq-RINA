/*
 *  Common definition placeholder
 *
 *    Francesco Salvestrini <f.salvestrini@nextworks.it>
 *    Sander Vrijders <sander.vrijders@intec.ugent.be>
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

#ifndef RINA_COMMON_H
#define RINA_COMMON_H

#include <linux/types.h>

typedef uint16_t      port_id_t;
typedef int           ipc_process_id_t;
typedef unsigned char string_t;
typedef int           bool_t;
typedef uint          uint_t;
typedef uint          response_reason_t;

/* This structure represents raw data */
struct buffer_t {
	char * data;
	size_t size;
};

struct sdu_t {
        struct buffer_t *buffer;
};

struct name_t {
	/*
	 * The process_name identifies an application
	 * process within the application process namespace
	 *
	 * This value is required, it cannot be NULL
	 *
	 * This name has global scope (it is defined by the chain of
	 * IDD databases that are linked together), and is assigned by
	 * an authority that manages the namespace that particular
	 * application name belongs to.
	 */
	string_t *process_name;
	/*
	 * The process_instance identifies a particular instance of the
	 * process.
	 *
	 * This value is optional, it may be NULL
	 *
	 */
	string_t *process_instance;
	/*
	 * The entity_name identifies an application entity within the
	 * application process.
	 *
	 * This value is optional, it may be NULL
	 */
	string_t *entity_name;
	/*
	 * The entity_name identifies a particular instance of an
	 * entity within the application process.
	 *
	 * This value is optional, it may be NULL
	 */
	string_t *entity_instance;
};

struct uint_range_t {
	/*
	 * This structure represents a range of integer values
	 */
	/* Minimum value */
	uint_t min_value;
        /* Maximum value */
	uint_t max_value;
};

struct flow_spec_t {
	/* This structure defines the characteristics of a flow */
	/* Average bandwidth in bytes/s */
	struct uint_range_t *average_bandwidth;
	/* Average bandwidth in SDUs/s */
	struct uint_range_t *average_sdu_bandwidth;
	/* In milliseconds */
	struct uint_range_t *peak_bandwidth_duration;
	/* In milliseconds */
	struct uint_range_t *peak_sdu_bandwidth_duration;
	/* A value of 0 indicates 'do not care' */
	double               undetected_bit_error_rate;
	/* Indicates if partial delivery of SDUs is allowed or not */
	bool_t               partial_delivery;
	/* Indicates if SDUs have to be delivered in order */
	bool_t               ordered_delivery;
	/*
	 * Indicates the maximum gap allowed among SDUs, a gap of N
	 * SDUs is considered the same as all SDUs delivered.
	 * A value of -1 indicates 'Any'
	 */
	int                  max_allowable_gap;
	/*
	 * In milliseconds, indicates the maximum delay allowed in this
	 * flow. A value of 0 indicates 'do not care'
	 */
	uint_t               delay;
	/*
	 * In milliseconds, indicates the maximum jitter allowed
	 * in this flow. A value of 0 indicates 'do not care'
	 */
	uint_t              jitter;
	/*
	 * The maximum SDU size for the flow. May influence the choice
	 * of the DIF where the flow will be created.
	 */
	uint_t              max_sdu_size;
};

#endif
