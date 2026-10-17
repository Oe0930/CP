; ModuleID = 'probe7.a61b64f89e40959b-cgu.0'
source_filename = "probe7.a61b64f89e40959b-cgu.0"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; probe7::probe
; Function Attrs: nonlazybind uwtable
define void @_RNvCsegboc5HC8iZ_6probe75probe() unnamed_addr #0 {
start:
  %0 = alloca [8 x i8], align 8
  %_1 = alloca [8 x i8], align 1
; call <f64>::to_ne_bytes
  %1 = call i64 @_RNvMNtCscI6d9CVNmLh_4core3f64d11to_ne_bytesCsegboc5HC8iZ_6probe7(double 3.140000e+00)
  store i64 %1, ptr %0, align 8
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %_1, ptr align 8 %0, i64 8, i1 false)
  ret void
}

; <f64>::to_ne_bytes
; Function Attrs: inlinehint nonlazybind uwtable
define internal i64 @_RNvMNtCscI6d9CVNmLh_4core3f64d11to_ne_bytesCsegboc5HC8iZ_6probe7(double %self) unnamed_addr #1 {
start:
  %_0 = alloca [8 x i8], align 1
  store double %self, ptr %_0, align 1
  %0 = load i64, ptr %_0, align 1
  ret i64 %0
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias writeonly captures(none), ptr noalias readonly captures(none), i64, i1 immarg) #2

attributes #0 = { nonlazybind uwtable "probe-stack"="inline-asm" "target-cpu"="x86-64" }
attributes #1 = { inlinehint nonlazybind uwtable "probe-stack"="inline-asm" "target-cpu"="x86-64" }
attributes #2 = { nocallback nofree nounwind willreturn memory(argmem: readwrite) }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 8, !"PIC Level", i32 2}
!1 = !{i32 2, !"RtLibUseGOT", i32 1}
!2 = !{!"rustc version 1.97.0 (2d8144b78 2026-07-07)"}
