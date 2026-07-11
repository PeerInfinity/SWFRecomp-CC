#include <abc/abc_tool.hpp>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include <common.h>
#include <swf.hpp>
#include <abc/abc_parser.hpp>
#include <abc/abc_verifier.hpp>
#include <abc/abc_dump.hpp>

using std::endl;
using std::string;

namespace SWFRecomp
{
namespace abc
{
	struct AbcTagPayload
	{
		bool has_header = false;  // tag 82 carries flags + name; tag 72 does not
		u32 flags = 0;
		string name;
		const u8* data = nullptr;
		size_t len = 0;
	};

	// Scans the (decompressed) SWF tag stream for DoABC (72/82) and
	// SymbolClass (76) tags. Everything else is skipped.
	static void scanSwfForAbc(SWF& swf, std::vector<AbcTagPayload>& abc_tags,
	                          std::vector<SymbolClassBinding>& symbols)
	{
		SWFTag tag;
		tag.code = (TagType) 1;
		char* cur_pos = swf.cur_pos;
		char* swf_end = swf.swf_buffer + swf.header.file_length;

		while (tag.code != 0)
		{
			if (cur_pos >= swf_end)
			{
				break;
			}
			tag.parseHeader(cur_pos);
			char* tag_data_end = cur_pos + tag.length;
			if (tag_data_end > swf_end)
			{
				break;
			}

			switch ((int) tag.code)
			{
				case SWF_TAG_DO_ABC:        // 82: Flags(UI32) + Name(STRING) + ABCData
				case SWF_TAG_DO_ABC_DEFINE: // 72: ABCData only
				{
					AbcTagPayload payload;
					const u8* p = (const u8*) cur_pos;
					const u8* p_end = (const u8*) tag_data_end;

					if ((int) tag.code == SWF_TAG_DO_ABC)
					{
						payload.has_header = true;
						if (p + 4 > p_end)
						{
							break;
						}
						payload.flags = (u32) p[0] | ((u32) p[1] << 8)
						              | ((u32) p[2] << 16) | ((u32) p[3] << 24);
						p += 4;
						while (p < p_end && *p != 0)
						{
							payload.name += (char) *p;
							++p;
						}
						if (p < p_end)
						{
							++p;  // NUL terminator
						}
					}

					payload.data = p;
					payload.len = (size_t) (p_end - p);
					abc_tags.push_back(payload);
					break;
				}

				case SWF_TAG_SYMBOL_CLASS:  // 76: Count(UI16) + Count*[Tag(UI16) + Name(STRING)]
				{
					const u8* p = (const u8*) cur_pos;
					const u8* p_end = (const u8*) tag_data_end;
					if (p + 2 > p_end)
					{
						break;
					}
					u16 count = (u16) (p[0] | (p[1] << 8));
					p += 2;
					for (u16 i = 0; i < count && p + 2 <= p_end; ++i)
					{
						SymbolClassBinding binding;
						binding.char_id = (u16) (p[0] | (p[1] << 8));
						p += 2;
						while (p < p_end && *p != 0)
						{
							binding.class_name += (char) *p;
							++p;
						}
						if (p < p_end)
						{
							++p;
						}
						symbols.push_back(binding);
					}
					break;
				}

				default: break;
			}

			cur_pos = tag_data_end;
		}
	}

	struct CheckResult
	{
		string status = "OK";   // OK | NO_ABC | PARSE_FAIL | VERIFY_FAIL
		int abc_tags = 0;
		int bodies = 0;
		int verify_fails = 0;
		string first_error;
		std::vector<string> verify_fail_lines;
	};

	static CheckResult checkAbcInSwf(const string& path, bool dump)
	{
		CheckResult result;

		Context context;
		context.swf_path = path;
		SWF swf(context);

		std::vector<AbcTagPayload> abc_tags;
		std::vector<SymbolClassBinding> symbols;
		scanSwfForAbc(swf, abc_tags, symbols);

		result.abc_tags = (int) abc_tags.size();
		if (abc_tags.empty())
		{
			result.status = "NO_ABC";
			return result;
		}

		for (size_t t = 0; t < abc_tags.size(); ++t)
		{
			const AbcTagPayload& payload = abc_tags[t];

			if (dump)
			{
				std::cout << "=== DoABC tag " << t;
				if (payload.has_header)
				{
					std::cout << " (flags=0x" << std::hex << payload.flags << std::dec
					          << ", name=\"" << payload.name << "\")";
				}
				std::cout << ", " << payload.len << " bytes ===" << endl;
			}

			AbcFile abc_file;
			string parse_error;
			if (!parseAbc(payload.data, payload.len, abc_file, parse_error))
			{
				result.status = "PARSE_FAIL";
				result.first_error = parse_error;
				return result;
			}

			VerifyError verr;
			if (!validateAbcFile(abc_file, verr))
			{
				result.status = "PARSE_FAIL";
				result.first_error = "validate: " + verr.message;
				return result;
			}

			if (dump)
			{
				result.verify_fails += dumpAbc(abc_file, std::cout);
				result.bodies += (int) abc_file.method_bodies.size();
			}
			else
			{
				for (size_t b = 0; b < abc_file.method_bodies.size(); ++b)
				{
					result.bodies += 1;
					IrMethod ir;
					VerifyError err;
					if (!verifyMethodBody(abc_file, (u32) b, ir, err))
					{
						result.verify_fails += 1;
						string method_name = "?";
						u32 mi = abc_file.method_bodies[b].method;
						if (mi < abc_file.methods.size()
						    && abc_file.methods[mi].name < abc_file.pool.strings.size())
						{
							method_name = abc_file.pool.strings[abc_file.methods[mi].name];
						}
						result.verify_fail_lines.push_back(
							"body=" + std::to_string(b)
							+ " method=\"" + method_name + "\""
							+ " code=" + std::to_string(err.code)
							+ " msg=\"" + err.message + "\"");
						if (result.first_error.empty())
						{
							result.first_error = err.message;
						}
					}
				}
			}
		}

		if (dump && !symbols.empty())
		{
			std::cout << endl << "SymbolClass bindings (" << symbols.size() << "):" << endl;
			for (const SymbolClassBinding& s : symbols)
			{
				std::cout << "  char " << s.char_id << " -> " << s.class_name;
				if (s.char_id == 0)
				{
					std::cout << " (root/main timeline)";
				}
				std::cout << endl;
			}
		}

		if (result.verify_fails > 0)
		{
			result.status = "VERIFY_FAIL";
		}
		return result;
	}

	int abcToolMain(int argc, char** argv)
	{
		bool dump = strcmp(argv[1], "--dump-abc") == 0;
		int worst = 0;

		for (int i = 2; i < argc; ++i)
		{
			string path = argv[i];
			CheckResult result;
			try
			{
				result = checkAbcInSwf(path, dump);
			}
			catch (const std::exception& e)
			{
				result.status = "SWF_LOAD_FAIL";
				result.first_error = e.what();
			}
			catch (...)
			{
				result.status = "SWF_LOAD_FAIL";
				result.first_error = "unknown exception";
			}

			// Machine-readable summary line (the sweep script greps these).
			std::cout << "ABC-CHECK " << path
			          << " status=" << result.status
			          << " abc_tags=" << result.abc_tags
			          << " bodies=" << result.bodies
			          << " verify_fails=" << result.verify_fails;
			if (!result.first_error.empty())
			{
				std::cout << " first_error=\"" << result.first_error << "\"";
			}
			std::cout << endl;
			for (const string& line : result.verify_fail_lines)
			{
				std::cout << "ABC-VERIFY-FAIL " << path << " " << line << endl;
			}

			int rank = result.status == "OK" ? 0
			         : result.status == "NO_ABC" ? 1
			         : result.status == "VERIFY_FAIL" ? 2 : 3;
			if (rank > worst)
			{
				worst = rank;
			}
		}

		fflush(stdout);
		return worst;
	}
}
}
