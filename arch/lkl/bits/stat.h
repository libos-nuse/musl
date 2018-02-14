/* copied from kernel definition (include/uapi/asm-generic/stat.h),
 * but with struct timespec replaced by the corresponding correctly-sized
 * userspace types. */

struct stat {
	unsigned long	st_dev;		/* Device.  */
	unsigned long	st_ino;		/* File serial number.  */
	unsigned int	st_mode;	/* File mode.  */
	unsigned int	st_nlink;	/* Link count.  */
	unsigned int	st_uid;		/* User ID of the file's owner.  */
	unsigned int	st_gid;		/* Group ID of the file's group. */
	unsigned long	st_rdev;	/* Device number, if device.  */
	unsigned long	__pad1;
	long		st_size;	/* Size of file, in bytes.  */
	int		st_blksize;	/* Optimal block size for I/O.  */
	int		__pad2;
	long		st_blocks;	/* Number 512-byte blocks allocated. */
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	unsigned int	__unused4;
	unsigned int	__unused5;
};
