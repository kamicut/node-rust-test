extern crate libc;

use std::slice;
use std::mem;

#[repr(C)]
pub struct Array {
    data: *const libc::c_void,
    len: i32,
}

impl Array {
    fn from_vec<T>(mut vec: Vec<T>) -> Array {
        vec.shrink_to_fit();
        let array = Array { data: vec.as_ptr() as *const libc::c_void, len: vec.len() as i32 };

        mem::forget(vec);

        array
    }
}

#[no_mangle]
pub extern fn julia(n: i32) -> Array {
    let mut vec = Vec::new();
    for i in 0..n {
       vec.push(1);
    }

    Array::from_vec(vec)
}
