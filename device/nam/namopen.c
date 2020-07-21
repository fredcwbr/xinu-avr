/* namopen.c - namopen */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  namopen  -  Open a file or device based on the name
 *------------------------------------------------------------------------
 */
devcall	namopen(
	  // struct dentry *devptr,	/* Entry in device switch table */
	  const __flash struct dentry *devptr,	/* Entry in device switch table */
	  char	*name,			/* Name to open			*/
	  char	*mode			/* Mode argument		*/
	)
{
	char	newname[NM_MAXLEN];	/* Name with prefix replaced	*/
	did32	newdev;			/* Device ID after mapping	*/

	/* Use namespace to map name to a new name and new descriptor */

	newdev = nammap(name, newname, devptr->dvnum);
	
	//RAFA
	kprintf("i:%s", name);
	kprintf("i2:%s", newname);
	kprintf("i3:%d", newdev);
	if (newdev == SYSERR) {
		// RAFA
		kprintf("error nam open\n");
		return SYSERR;
	}

	/* Open underlying device and return status */

	return  open(newdev, newname, mode);
}
