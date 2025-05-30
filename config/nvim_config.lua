-- This is the code that goes into your
-- project_root_directory/config/nvim_config.lua

---- Plugin Imports ----
require('nvim-tree').setup()
require('vscode').load('dark')
require('Comment').setup()

---- Key remappings ----
vim.g.mapleader = " "
vim.keymap.set("n", "<leader>pv", vim.cmd.Ex) -- Exits vim

-- Plugin remappings
local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>ff', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<leader>fg', builtin.live_grep, { desc = 'Telescope live grep' })
vim.keymap.set('n', '<leader>fb', builtin.buffers, { desc = 'Telescope buffers' })
vim.keymap.set('n', '<leader>fh', builtin.help_tags, { desc = 'Telescope help tags' })
vim.keymap.set('n', '<leader>ot', vim.cmd.NvimTreeOpen)
vim.keymap.set('n', '<leader>nt', function()
    vim.cmd('tabnew')
    vim.cmd('NvimTreeOpen')
end)

---- Vim Settings ----
vim.opt.shiftwidth = 4
vim.opt.relativenumber = true
vim.lsp.enable('pyright')
