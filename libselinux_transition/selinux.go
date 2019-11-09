package main


// #cgo pkg-config: libselinux libsepol
// #include <selinux/selinux.h>
// #include <stdlib.h>
import "C"
import "fmt"


func main() {
    x := []string {
        "test_setexeccon_t",
        "passwd_t",
	"chrome_sandbox_t",
	"sandbox_x_domain",
	"kpatch_t",
    }
    for _, element := range x {
        var scon string = "unconfined_u:unconfined_r:"+ element + ":s0"
        //var scon string = "unconfined_u:unconfined_r:passwd_t:s0"
        var val *C.char
        
        fmt.Println("Set exec context: ", scon)
        val = C.CString(scon)
        rc, err := C.setexeccon(val)
        fmt.Println("Set exec context rc: ", rc, ", err: ", err )
    }
}

