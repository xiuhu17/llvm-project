// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple i386-linux-gnu -emit-llvm -o - %s | FileCheck %s

typedef struct {} empty;

// CHECK-LABEL: @_Z17empty_record_testiz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RESULT_PTR:%.*]] = alloca ptr, align 4
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca ptr, align 4
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_EMPTY:%.*]], align 1
// CHECK-NEXT:    store ptr [[AGG_RESULT:%.*]], ptr [[RESULT_PTR]], align 4
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[LIST]])
// CHECK-NEXT:    ret void
//
empty empty_record_test(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, empty);
}
