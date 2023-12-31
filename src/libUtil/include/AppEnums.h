/*
 *------------------------------------------------------------------------
 * abc.h
 *
 * No  any Corporation or client funds were used to develop this code.
 * But the numerical receip's LU decomposition algorithm is adopted.
 *
 * Copyright (c) 2022 Shunguang Wu
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT SHALL THE AUTHOR OR DISTRIBUTOR BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 *-------------------------------------------------------------------------
 */

#ifndef __APP_ENUMS_H__
#define __APP_ENUMS_H__
#include "libUtil/include/AppDefs.h"
namespace app {
	struct ImgSize {
		ImgSize(int w_ = 0, int h_ = 0) : w(w_), h(h_) {}
		ImgSize(const ImgSize& x) :w(x.w), h(x.h) {}
		void set(int w_, int h_) {
			w = w_;
			h = h_;
		}
		bool isSame(int w_, int h_) const {
			return ((w == w_) && (h == h_));
		}

		ImgSize getSize(int L) const {
			ImgSize sz(w >> L, h >> L);
			return sz;
		}

		int w;
		int h;
	};

	struct VideoFps {
		VideoFps(int num_ = 0, int den_ = 1) : num(num_), den(den_) {}
		void set(int num_, int den_) {
			num = num_;
			den = den_;
		}
		bool isSame(int num_, int den_) const {
			return ((num == num_) && (den == den_));
		}
		float getFps() const {
			return (float)num / den;
		}
		int num;
		int den;
	};

	struct Frequency {
		Frequency(int start_ = 0, int step_ = 0, int end_ = 1) : start(start_), step(step_), end(end_) {}
		void set(int start_, int step_, int end_) {
			start = start_;
			step = step_;
			end = end_;
		}

		bool isSame(int start_, int step_, int end_) const {
			return ((start == start_) && (step == step_) && (end == end_));
		};

		int start;
		int step;
		int end;
	};
}
#endif
