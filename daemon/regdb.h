#include <linux/types.h>

/* spells "RGDB" */
#define REGDB_MAGIC	0x52474442

/*
 * Only supported version now, start at arbitrary number
 * to have some more magic :)
 */
#define REGDB_VERSION	19

struct regdb_file_header {
	/* must be REGDB_MAGIC */
	__be32	magic;
	/* must be REGDB_VERSION */
	__be32	version;
	/* pointer (offset) into file where country list starts */
	__be32	reg_country_ptr;
	__be32	reg_country_num;
};

struct regdb_file_reg_rule {
	/* pointers (offsets) into the file */
	__be32	freq_range_ptr;
	__be32	power_rule_ptr;
};

struct regdb_file_freq_range {
	__be32	start_freq,
		end_freq,
		max_bandwidth,
		modulation_cap,
		misc_restrictions;
};

struct regdb_file_power_rule {
	__u8	environment_cap;
	__u8	PAD[3];
	__be32	max_antenna_gain,
		max_ir_ptmp,
		max_ir_ptp,
		max_eirp_pmtp,
		max_eirp_ptp;
};

struct regdb_file_reg_rules_collection {
	__be32	reg_rule_num;
	/* pointers (offsets) into the file */
	__be32	reg_rule_ptrs[];
};

struct regdb_file_reg_country {
	__u8	alpha2[2];
	__u8	PAD[2];
	/* pointer (offset) into the file */
	__be32	reg_collection_ptr;
};