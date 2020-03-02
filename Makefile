##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## nmobjdump
##

NAME_OBJDUMP	=	my_objdump

NAME_NM		=	my_nm

NAME_TESTS	=	unit_tests

SRCS_NM		=		nm/src/main.c	\
					nm/src/nm.c	\
					nm/src/display_informations.c	\
					nm/src/display_symbols.c	\
					nm/src/symbol_struct/init_symbols.c	\
					nm/src/symbol_struct/free_symbols.c	\
					nm/src/symbol_struct/letters/is_maj_a.c	\
					nm/src/symbol_struct/letters/is_maj_b.c	\
					nm/src/symbol_struct/letters/is_maj_c.c	\
					nm/src/symbol_struct/letters/is_maj_d.c	\
					nm/src/symbol_struct/letters/is_maj_r.c	\
					nm/src/symbol_struct/letters/is_maj_t.c	\
					nm/src/symbol_struct/letters/is_maj_u.c	\
					nm/src/symbol_struct/letters/is_maj_v.c	\
					nm/src/symbol_struct/letters/is_maj_w.c	\
					nm/src/symbol_struct/letters/is_min_a.c	\
					nm/src/symbol_struct/letters/is_min_b.c	\
					nm/src/symbol_struct/letters/is_min_c.c	\
					nm/src/symbol_struct/letters/is_min_d.c	\
					nm/src/symbol_struct/letters/is_min_r.c	\
					nm/src/symbol_struct/letters/is_min_t.c	\
					nm/src/symbol_struct/letters/is_min_u.c	\
					nm/src/symbol_struct/letters/is_min_v.c	\
					nm/src/symbol_struct/letters/is_min_w.c	\
					nm/src/rewrite_functions/close_file.c	\
					nm/src/rewrite_functions/open_file.c	\
					nm/src/rewrite_functions/wrong_file_format.c	\
					nm/src/rewrite_functions/path_is_directory.c	\
					nm/src/rewrite_functions/good_version.c	\
					nm/src/rewrite_functions/wrong_type.c	\
					nm/src/sort_symbols/compare_symbols.c	\
					nm/src/sort_symbols/list_is_not_sort.c	\
					nm/src/sort_symbols/sort_symbols.c	\

SRCS_OBJDUMP	=	objdump/src/main.c	\
					objdump/src/objdump.c	\
					objdump/src/display_information.c	\
					objdump/src/overall_header/display_overall_header.c	\
					objdump/src/overall_header/display_file_format.c	\
					objdump/src/overall_header/display_architecture.c	\
					objdump/src/overall_header/display_flags.c	\
					objdump/src/overall_header/display_start_adress.c	\
					objdump/src/sections/display_sections.c	\
					objdump/src/sections/display_bytes.c	\
					objdump/src/sections/printf_string.c	\
					objdump/src/rewrite_functions/close_file.c	\
					objdump/src/rewrite_functions/open_file.c	\
					objdump/src/rewrite_functions/wrong_file_format.c	\
					objdump/src/rewrite_functions/path_is_directory.c	\
					objdump/src/rewrite_functions/good_version.c	\
					objdump/src/rewrite_functions/wrong_type.c	\

SRCS_TESTS	=	\

SRCS_ELF	=		src/init_elf_struct.c	\
					src/destroy_elf_struct.c	\
					src/init_elfs_struct.c	\
					src/init_phdr_struct.c	\
					src/init_shdr_struct.c	\
					src/init_sym_struct.c	\
					src/init_ehdr_struct.c	\
					src/init_flags.c	\
					src/flags/flag_d_paged.c	\
					src/flags/flag_dynamic.c	\
					src/flags/flag_exec_p.c	\
					src/flags/flag_has_debug.c	\
					src/flags/flag_has_lineno.c	\
					src/flags/flag_has_locals.c	\
					src/flags/flag_has_reloc.c	\
					src/flags/flag_has_syms.c	\
					src/flags/flag_wp_text.c	\
					src/ehdr/get_e_ehsize.c	\
					src/ehdr/get_e_entry.c	\
					src/ehdr/get_e_flags.c	\
					src/ehdr/get_e_ident.c	\
					src/ehdr/get_e_machine.c	\
					src/ehdr/get_e_phentsize.c	\
					src/ehdr/get_e_phnum.c	\
					src/ehdr/get_e_phoff.c	\
					src/ehdr/get_e_shentsize.c	\
					src/ehdr/get_e_shnum.c	\
					src/ehdr/get_e_shoff.c	\
					src/ehdr/get_e_shstrndx.c	\
					src/ehdr/get_e_type.c	\
					src/ehdr/get_e_version.c	\
					src/phdr/get_p_align.c	\
					src/phdr/get_p_filesz.c	\
					src/phdr/get_p_flags.c	\
					src/phdr/get_p_memsz.c	\
					src/phdr/get_p_offset.c	\
					src/phdr/get_p_paddr.c	\
					src/phdr/get_p_type.c	\
					src/phdr/get_p_vaddr.c	\
					src/shdr/get_sh_addr.c	\
					src/shdr/get_sh_addralign.c	\
					src/shdr/get_sh_entsize.c	\
					src/shdr/get_sh_flags.c	\
					src/shdr/get_sh_info.c	\
					src/shdr/get_sh_link.c	\
					src/shdr/get_sh_name.c	\
					src/shdr/get_sh_offset.c	\
					src/shdr/get_sh_size.c	\
					src/shdr/get_sh_type.c	\
					src/sym/get_st_name.c	\
					src/sym/get_symbol_name.c	\
					src/sym/get_st_info.c	\
					src/sym/get_st_other.c	\
					src/sym/get_st_shndx.c	\
					src/sym/get_st_size.c	\
					src/sym/get_st_value.c	\
					src/error/file_has_error.c	\
					src/error/good_ident.c	\
					src/error/good_type.c	\

OBJS_NM	=	$(SRCS_NM:.c=.o)

OBJS_OBJDUMP	=	$(SRCS_OBJDUMP:.c=.o)

OBJS_TESTS		=	$(SRCS_TESTS:.c=.o)

OBJS_ELF	=	$(SRCS_ELF:.c=.o)

CFLAGS	=	-W -Wall -Wextra

LDFLAGS	=	\

CC	=	gcc

RM		=		rm -f

all: $(OBJS_ELF) $(NAME_NM) $(NAME_OBJDUMP)

nm: $(OBJS_ELF) $(NAME_NM)

objdump: $(OBJS_ELF) $(NAME_OBJDUMP)

$(NAME_NM): $(OBJS_NM)
			$(CC) -o $(NAME_NM) $(OBJS_NM) $(OBJS_ELF) $(LDFLAGS)

$(NAME_OBJDUMP): $(OBJS_OBJDUMP)
			$(CC) -o $(NAME_OBJDUMP) $(OBJS_OBJDUMP) $(OBJS_ELF) $(LDFLAGS)

clean:
	$(RM) $(OBJS_NM)
	$(RM) $(OBJS_OBJDUMP)
	$(RM) $(OBJS_ELF)

clean_objdump:
	$(RM) $(OBJS_OBJDUMP)

fclean: clean
	$(RM) $(NAME_NM)
	$(RM) $(NAME_OBJDUMP)

fclean_objdump: clean_objdump
	$(RM) $(NAME_OBJDUMP)

re: fclean all

re_nm: fclean nm
re_objdump: fclean objdump

tests_run:	LDFLAGS += -lcriterion --coverage
tests_run: 	CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: fclean $(OBJS_TESTS)
			$(CC) -o $(NAME_TESTS) $(OBJS_TESTS) $(LDFLAGS)
			./$(NAME_TESTS)

debug: CFLAGS += -g
debug: re

debug_objdump: CFLAGS += -g
debug_objdump: re_objdump

functional_tests: re
			./tests/objdump/functional/tests.sh
			./tests/nm/functional/tests.sh

.PHONY: all nm objdump clean fclean re debug tests_run re_nm re_objdump clean_objdump fclean_objdump debug_objdump functional_tests